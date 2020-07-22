#include <stdio.h>
#include <stdlib.h>

// 题目描述     https://www.nowcoder.com/ta/huawei
// 计算24点是一种扑克牌益智游戏，随机抽出4张扑克牌，通过加(+)，减(-)，乘(*), 
// 除(/)四种运算法则计算得到整数24，本问题中，扑克牌通过如下字符或者字符串表示，其中，小写joker表示小王，大写JOKER表示大王： 
//                    3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER
// 本程序要求实现：输入4张牌，输出一个算式，算式的结果为24点。 
// 详细说明：
// 1.运算只考虑加减乘除运算，没有阶乘等特殊运算符号，友情提醒，整数除法要当心； 
// 2.牌面2~10对应的权值为2~10, J、Q、K、A权值分别为为11、12、13、1； 
// 3.输入4张牌为字符串形式，以一个空格隔开，首尾无空格；如果输入的4张牌中包含大小王，则输出字符串“ERROR”，表示无法运算； 
// 4.输出的算式格式为4张牌通过+-*/四个运算符相连，中间无空格，4张牌出现顺序任意，只要结果正确； 
// 5.输出算式的运算顺序从左至右，不包含括号，如1+2+3*4的结果为24
// 6.如果存在多种算式都能计算得出24，只需输出一种即可，如果无法得出24，则输出“NONE”表示无解。

// 输入描述:
// 输入4张牌为字符串形式，以一个空格隔开，首尾无空格；

// NICE = +-*/

int * str2Array (char * poker){
    int result[4] = {0, 0, 0, 0};
    // "ERROR" == 44
    
    for ( int i=0; i < 7; i++){
        if (*(poker+i) == '2'){
            result[i] = 2;
        }
        else if (*(poker+i) == '3'){
            result[i] = 3;
        }
        else if (*(poker+i) == '4'){
            result[i] = 4;
        }
        else if (*(poker+i) == '5'){
            result[i] = 5;
        }
        else if (*(poker+i) == '6'){
            result[i] = 6;
        }
        else if (*(poker+i) == '7'){
            result[i] = 7;
        }
        else if (*(poker+i) == '8'){
            result[i] = 8;
        }
        else if (*(poker+i) == '9'){
            result[i] = 9;
        }
        else if (*(poker+i) == '10'){
            result[i] = 10;
        }
        else if (*(poker+i) == 'A'){
            result[i] = 1;
        }
        else if (*(poker+i) == 'Q'){
            result[i] = 12;
        }
        else if (*(poker+i) == 'K'){
            result[i] = 13;
        }
        else if (*(poker+i) == 'j'){
            result[i] = 44;
        }
        else if (*(poker+i) == 'J'){
            if (*(poker+i+1) == ' '){
                result[i] = 11;
            }
            else{ result[i] = 44;}
        }
        else if(*(poker+i) == ' '){
            continue;
        } 
    }
    return result;
} 

