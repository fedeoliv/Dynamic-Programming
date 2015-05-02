#include <cstdio>
#include <set>
#define MAXN 1000005
using namespace std;

int main() {
    int n, a[MAXN];
    set<int> s;
    set<int>::iterator it;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);

        s.insert(a[i]);
        it = s.find(a[i]);
        it++;

        if(it != s.end()) s.erase(it);
    }

    for(it = s.begin(); it != s.end(); ++it) printf("%d ", *it);
    printf("\n");
    printf("Length: %d\n", s.size());
    return 0;
}
