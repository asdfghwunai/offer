/*
汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。
对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,
要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！
*/

class Solution {
public:
    string LeftRotateString(string str, int n) {
        for(int i=0;i<n;i++)  //首先确定循环次数
        {
            char c=str[0];    
            for(int j=1;j<str.size();j++)
            {
                str[j-1]=str[j];
            }
            //str.insert(prev(str.end()),c);  //不是插入
            str[str.size()-1]=c;
        }
        return str;  //这也证明不能return引用和指针
    }
};

/*
反正就是一个规律
*/

class Solution {
public:
    string LeftRotateString(string str, int n) {
        if(str.size()==0)
            return "";
        reverse(str.begin(),str.begin()+n);
        reverse(str.begin()+n,str.end());
        
        reverse(str.begin(),str.end());
        
        return str;
    }
};
