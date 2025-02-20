// class Solution {
//     public:
//       string roman(int num){
//          if (num >= 1000) return "M";
//             else if (num >= 900) return "CM";
//             else if (num >= 500) return "D";
//             else if (num >= 400) return "CD";
//             else if (num >= 100) return "C";
//             else if (num >= 90) return "XC";
//             else if (num >= 50) return "L";
//             else if (num >= 40) return "XL";
//             else if (num >= 10) return "X";
//             else if (num >= 9) return "IX";
//             else if (num >= 5) return "V";
//             else if (num >= 4) return "IV";
//             else return "I";
//       }
    
//         int getValue(string s) {
//             if (s == "M") return 1000;
//             if (s == "CM") return 900;
//             if (s == "D") return 500;
//             if (s == "CD") return 400;
//             if (s == "C") return 100;
//             if (s == "XC") return 90;
//             if (s == "L") return 50;
//             if (s == "XL") return 40;
//             if (s == "X") return 10;
//             if (s == "IX") return 9;
//             if (s == "V") return 5;
//             if (s == "IV") return 4;
//             return 1;
//         }
    
//         string intToRoman(int num) {
//               string result = "";
//               while(num>0){
//                 string symbol = roman(num);
//                 result += symbol;
//                 num -= getValue(symbol);
//               }
//            return result;
//         }
//     };