#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <typeinfo>
using namespace std;

int fib1(int n) {
    if(n <= 1)
        return n;
    int a = fib1(n - 1);
    int b = fib1(n - 2);
    return a + b;
}
int helper_fib2(int n, int *ans) {
    if(n <= 1) {
        return n;
    }
    if(ans[n] != -1) {
        return ans[n];
    }
    int a = helper_fib2(n - 1, ans);
    int b = helper_fib2(n - 2, ans);
    ans[n] = a + b;
    return ans[n];
}
int fib2(int n) {
    int *ans = new int[n + 1];
    for(int i = 0; i < n + 1; i++) {
        ans[i] = 0;
    }
    return helper_fib2(n, ans);
}
int fib3(int n) {
    int *ans = new int[n + 1];
    ans[0] = 0;
    ans[1] = 1;
    for(int i = 2; i <= n; i++) { 
        ans[i] = ans[i-1] + ans[i-2];
    }
    return ans[n];
}

///////////////////Count min steps to one/////////////////////
//Using simple recursion
int countMinStepsToOne(int n)
{
	//Write your code here
    if(n <= 1)
        return 0;
    int a = countMinStepsToOne(n - 1);
    int b = INT_MAX, c = b;
    if(n % 2 == 0) {
        b = countMinStepsToOne(n / 2);
    }
    if(n % 3 == 0) {
        c = countMinStepsToOne(n / 3);
    }
    int minSteps = min(a, min(b, c));
    return minSteps + 1;
}

//Using memoization
int helper_countMinStepsToOne2(int n, int *ans) {
    if(n <= 1)
        return 0;
    if(ans[n] != -1) {
        return ans[n];
    }
    int a = helper_countMinStepsToOne2(n - 1, ans);
    int b = INT_MAX, c = b;
    if(n % 2 == 0) {
        b = helper_countMinStepsToOne2(n / 2, ans);
    }
    if(n % 3 == 0) {
        c = helper_countMinStepsToOne2(n / 3, ans);
    }
    int minSteps = min(a, min(b, c));
    ans[n] = minSteps + 1;
    return ans[n];
}
int countMinStepsToOne2(int n)
{
	//Write your code here
    int *ans = new int[n + 1];
    for(int i = 0; i < n + 1; i++) {
        ans[i] = -1;
    }
    return helper_countMinStepsToOne2(n, ans);
}

int countMinStepsToOne3(int n)
{
	int *ans = new int[n + 1];
    for(int i = 0; i <= n; i++) {
        ans[i] = 0;
    }
    int ms1, ms2, ms3;
    for(int i = 2; i <= n; i++) {
        ms1 = ans[i - 1];
        ms2 = ms3 = INT_MAX;
        if(i % 2 == 0) {
            ms2 = ans[i / 2];
        }
        if(i % 3 == 0) {
            ms3 = ans[i / 3];
        }
        int minSteps = min(ms1, min(ms2, ms3)) + 1;
        ans[i] = minSteps;
    }
    int res = ans[n];
    delete ans;
    return res;
}

//////////////////////STAIR CASE///////////////////////////
long staircase_helper(int n, int &ans) {
    if(n <= 0) {
        return 1;
    }
    int a, b, c;
    a = b = c = 0;
    a = staircase_helper(n - 1, ans);
    if(n - 2 >= 0) {
        b = staircase_helper(n - 2, ans);
    }
    if(n - 3 >= 0) {
        c = staircase_helper(n - 3, ans);
    }
    return a + b + c;
}
long staircase(int n)
{
	//Write your code here
    if(n <= 0) {
        return 0;
    }
    long ans = 0;
    return staircase_helper(n, ans);
}

//using memoization
long stairCase2_helper(int n, long *ans) {
    if(n <= 0) {
        return 1;
    }
    int a, b, c;
    a = b = c = 0;
    if(ans[n - 1] != -1) {
        a = ans[n - 1];
    }
    else {
        a = stairCase2_helper(n - 1, ans);
    }
    if(n - 2 >= 0) {
        if(ans[n - 2] != -1) {
            b = ans[n - 2];
        }
        else {
            b = stairCase2_helper(n - 2, ans);
        }
    }
    if(n - 3 >= 0) {
        if(ans[n - 3] != -1) {
            c = ans[n - 3];
        }
        else {
            c = stairCase2_helper(n - 3, ans);
        }
    }
    ans[n] = a + b + c;
    return a + b + c;
}
long staircase2(int n)
{
	//Write your code here
    long *ans = new long[n+1];
    for(int i = 0; i <= n; i++) {
        ans[i] = -1;
    }
    if(n <= 0) {
        return 0;
    }
    return stairCase2_helper(n, ans);
}

//using dp
long staircase_usingDP(int n)
{
	//Write your code here
    long *dp = new long[n+1];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    return dp[n];
}


///////////////////////MINIMUM COUNT////////////////////////
void minCount_helper(int n, vector<int>& ans, int steps)
{
	//Write your code here
    if(n <= 0) {
        ans.push_back(steps);
        return;
    }
    for(int i = 1; i <= n; i++) {
        int newN = n - i*i;
        if(newN >= 0) {
            steps++;
            minCount(newN, ans, steps);
            steps--;
        }
        else {
            break;
        }
    }
}
int minCount(int n) {
    vector<int> ans {};
    minCount(n, ans, 0);
    int mini = ans[0];
    for(int i = 0; i < ans.size(); i++) {
        mini = min(mini, ans[i]); 
    }
    return mini;
}

//using memoization
int minCount2(int n) {

}

//using DP
int minCount_usingDP(int n) {
    int count[n + 1];
    count[0] = 0;
    count[1] = 1;
    for(int i = 2; i <= n; i++) { 
        int ans = i;
        for(int j = 1; j <= sqrt(i); j++) { 
            int k = i - (j * j); 
            if(k >= 0) 
                ans = min(ans, count[k] + 1);
        }
        count[i] = ans;
    } 
    return count[n];
}


////////////////////NO. OF BALANCED BST/////////////////////

int balancedBTs(int h) {
    if(h <= 1) {
		return 1;
	}
	int mod = (int) (pow(10, 9)) + 7;
	int x = balancedBTs(h - 1);
	int y = balancedBTs(h - 2);
	int temp1 = (int)(((long)(x)*x) % mod);
	int temp2 = (int)((2* (long)(x) * y) % mod);
	int ans = (temp1 + temp2) % mod;
	//int ans = (x*x + 2*x*y) % mod;
	return ans;
}

//using dp
int balancedBTs_usingDP(int h) {
    // Write your code here
    int mod = (int) (pow(10, 9)) + 7;
    long dp[h + 1]; 
    //base cases 
    dp[0] = dp[1] = 1; 
    for(int i = 2; i <= h; i++) { 
        dp[i] = (dp[i - 1] * ((2 * dp [i - 2])%mod + dp[i - 1])%mod) % mod; 
    } 
    return dp[h];
}
int main() {
    int a = 10000;
    long b = 1000000;
    auto c = b*a;
    cout<<typeid(c).name();
    
}