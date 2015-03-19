#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <list>
#include <vector>
#include <map>
using namespace std;

int const wordcount = 25200;
int const wordsize = 20;

typedef vector<char *> wordtable;
struct strcomp
{ bool operator()(char *s1, char *s2) { return strcmp(s1, s2) < 0; } };
typedef map<char *, int, strcomp> wordmap;
typedef vector<vector<int> > wordgraph;
bool adjacent(char const *s1, char const* s2)
{
  bool adj = false;
  for (int i = 0; s1[i] != '/0'; ++i) {
    if (s1[i] != s2[i]) {
      adj = !adj;
      if (!adj) break;
    }
  }
  return adj;
}
void build_wordgraph(wordtable const& wt, wordgraph& wg)
{
  wg.resize(wt.size());
  for (int i = 0; i < wt.size() - 1; ++i) {
    for (int j = i + 1; j < wt.size(); ++j) {
      if (adjacent(wt[i], wt[j])) {
        wg[i].push_back(j);
        wg[j].push_back(i);
      }
    }
  }
}
bool get_doublets(wordgraph const& wg, int s, int t, list<int>& doublets)
{
  queue<int> q;
  vector<bool> visited(wg.size(), false);
  vector<int> previous(wg.size());
  q.push(s);
  visited[s] = true;
  bool found = false;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    if (v == t) {
      found = true;
      break;
    }
    for (int i = 0, size = wg[v].size(); i < size; ++i) {
      int a = wg[v][i];
      if (!visited[a]) {
        q.push(a);
        visited[a] = true;
        previous[a] = v;
      }
    }
  }

  if (found) {
    for (; t != s; t = previous[t]) doublets.push_front(t);
    doublets.push_front(t);
  }
  return found;
}
int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
  filebuf in, out;
  cin.rdbuf(in.open((string(argv[0]) + ".in").c_str(), ios_base::in));
  cout.rdbuf(out.open((string(argv[0]) + ".out").c_str(), ios_base::out));
#endif
  char words[wordcount][wordsize];
  int nwords = 0;
  for (; cin.getline(words[nwords], wordsize) && words[nwords][0] != '/0';
       ++nwords) {}
  /* index words by size */
  vector<wordtable> wts(wordsize);
  vector<wordmap> wms(wordsize);
  for (int i = 0; i < nwords; ++i) {
    int size = strlen(words[i]);
    wts[size].push_back(words[i]);
    wms[size].insert(make_pair(words[i], wts[size].size() - 1));
  }

  /* we will build wordgraph lazily */
  vector<wordgraph> wgs(wordsize);
  char source[wordsize], target[wordsize];
  int ncases = 0;
  while (cin >> source >> target) {
    if (ncases++ != 0) cout << '/n';
    list<int> doublets;
    bool found = false;
    int size = strlen(source);
    wordtable& wt = wts[size];
    wordmap& wm = wms[size];
    wordgraph& wg = wgs[size];
    if (size == strlen(target)) {
      if (wg.empty()) build_wordgraph(wt, wg);
      found = get_doublets(wg, wm[source], wm[target], doublets);
    }
    if (found) {
      list<int>::iterator first = doublets.begin(), last = doublets.end();
      for (; first != last; ++first) cout << wt[*first] << '/n';
    } else {
      cout << "No solution./n";
    }
  }
  return 0;
}
