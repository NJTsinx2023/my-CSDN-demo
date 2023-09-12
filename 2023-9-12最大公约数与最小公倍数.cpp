#include<bits/stdc++.h>

/*最大公约数与最小公倍数的关系  
两个数的乘积等于这两个数的最大公约数与最小公倍数的乘积。  a*b=最大公约数*最小公倍数 
*/
//1.穷举法
int gcd(int a,int b){
	int i;
	if(a<b){//a为大数  b为小 
		int t=a; 
		a=b;
		b=t;
	}
	for(i=b;i>0;i--){
		if(a%i==0&&b%i==0){
			return i;
		}
	} 
}
//倍数就不过多赘述了，因为只要学会最大公约数 ,最小公倍数就得出了，但也可以用穷举法 
//在接下来的里面就不在赘述最小公倍数的做法了，我们只用考虑最大公约数就可以了 
int beishu(int a,int b){

}
//2.更相减损法 
/*
也叫更相减损术，是出自《九章算术》的一种求最大公约数的算法，它原本是为约分而设计的，
但它适用于任何需要求最大公约数的场合。
第一步：任意给定两个正整数；判断它们是否都是偶数。若是，则用2约简；若不是则执行第二步。
第二步：以较大的数减较小的数，接着把所得的差与较小的数比较，并以大数减小数。继续这个操作，直到所得的减数和差相等为止。
则第一步中约掉的若干个2与第二步中等数的乘积就是所求的最大公约数。
其中所说的“等数”，就是最大公约数。求“等数”的办法是“更相减损”法。所以更相减损法也叫等值算法。
*/ 
int gcd2(int a,int b){
	while(a!=b){
		if(a>b){
			a=a-b;
		}
		else{
			b=b-a;
		}
	}
	return b;//这里因为a b都是相等的，所以无论返回哪个之都是可以的 
}


//3.辗转相除法 
//辗转相除法是求两个自然数的最大公约数的一种方法，也叫欧几里德算法。
/*
最大公约数思路：
 假设两个数字a和b，求两个数字相除的余数c=a%b，如果余数为0，则b为最大公约数。
 如果b不为零，a=b,b=c,继续循环计算。
*/

int gcd3(int a,int b){
	int c=0;
	while(a%b!=0){//注意辗转相除法与 更相减损法的区别，对a b 大小无要求 
		c=a%b;
		a=b;
		b=c;
	} 
	
	return b;
}


int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	printf("a=%d,b=%d的最大公约数为：%d\n",a,b,gcd3(a,b));
	printf("a=%d,b=%d的最小工倍数为：%d\n",a,b,a*b/gcd3(a,b));//最小公倍数就直接使用关系公式就可以了 
	return 0;
}
