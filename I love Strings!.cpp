#include <vector>
#include <algorithm>
#include <string>
#include <limits>
#include <stdio.h>
#include<iostream>
using namespace std;

const int inf = numeric_limits<int>::max();
typedef unsigned char UChar;

struct Link {
   int start, end;
   int to;


   Link() {
      to = -1;
   }

   Link(int _start, int _end, int _to) {
      start = _start;
      end = _end;
      to = _to;
   }
};


struct Vertex {
   vector<Link> links;
   int suffix;
   Vertex() {
      links.assign(256, Link());
      suffix = -1;
   }
};

vector<Vertex> tree;
int root, dummy;

string sample;

UChar t(int i) {
   return (i<0) ? (-i-1) : sample[i];
}


int newVertex()
{
   int i = tree.size();
   tree.push_back(Vertex());
   return i;
}


void link(int from, int start, int end, int to)
{
   tree[from].links[t(start)] = Link(start, end, to);
}


int &f(int v)
{
   return tree[v].suffix;
}


void initTree()
{
   tree.clear();
   dummy = newVertex();
   root = newVertex();

   f(root) = dummy;
   for(int i=0; i<256; i++)
      link(dummy, -i-1, -i, root);
}


pair<int, int> canonize(int v, int start, int end)
{
   if(end <= start) {
      return make_pair(v, start);
   } else {
      Link cur = tree[v].links[t(start)];
      while(end - start >= cur.end - cur.start) {
         start += cur.end - cur.start;
         v = cur.to;
         if(end > start)
            cur = tree[v].links[t(start)];
      }
      return make_pair(v, start);
   }
}

pair<bool, int> testAndSplit(int v, int start, int end, UChar c)
{
   if(end <= start) {
      return make_pair(tree[v].links[c].to != -1, v);
   } else {
      Link cur = tree[v].links[t(start)];
      if(c == t(cur.start + end - start))
         return make_pair(true, v);

      int middle = newVertex();
      link(v, cur.start, cur.start + end - start, middle);
      link(middle, cur.start + end - start, cur.end, cur.to);
      return make_pair(false, middle);
   }
}

pair<int, int> update(int v, int start, int end) {
   Link cur = tree[v].links[t(start)];
   pair<bool, int> splitRes;
   int oldR = root;

   splitRes = testAndSplit(v, start, end, t(end));
   while(!splitRes.first) {

      link(splitRes.second, end, inf, newVertex());


      if(oldR != root)
         f(oldR) = splitRes.second;
      oldR = splitRes.second;


      pair<int, int> newPoint = canonize(f(v), start, end);
      v = newPoint.first;
      start = newPoint.second;
      splitRes = testAndSplit(v, start, end, t(end));
   }
   if(oldR != root)
      f(oldR) = splitRes.second;
   return make_pair(v, start);
}


void ukkonen()
{

   initTree();


   pair<int, int> activePoint = make_pair(root, 0);
   for(int i=0; i<sample.length(); i++) {
      activePoint = update(activePoint.first, activePoint.second, i);
      activePoint = canonize(activePoint.first, activePoint.second, i+1);
   }
}


bool present(string word)
{
   int v=root, start=0, end=0;
   for(int i=0; i<word.length(); i++) {
      UChar cur = word[i];
      if(end==start) {
         if(tree[v].links[cur].to==-1) return false;
         start = tree[v].links[cur].start;
         end = start+1;
      } else {
         if(cur != t(end)) return false;
         end++;
      }
      if(end==tree[v].links[t(start)].end) {
         v = tree[v].links[t(start)].to;
         start=0;
         end=0;
      }
   }
   return true;
}

int main() {

   int cases, nQ;
   cin >> cases;
   while(cases--){
       cin >> sample;
       ukkonen();
        cin >> nQ;

       string hudai;

       while(nQ--)
        {
          string what;
          cin >> what;
          printf(present(what)? "y\n" : "n\n");

        }
   }
   return 0;
}
