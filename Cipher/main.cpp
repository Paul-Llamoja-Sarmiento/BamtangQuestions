/**************************************************************
 * This program decodes a message using a frecuency-based key**
 * Author: Paul A. Llamoja Sarmiento***************************
 * v1.0 *******************************************************
 * Date: 03/26/2021********************************************
 * ************************************************************/

#include <iostream>
#include <string>
#include <vector>

int main() 
{
        //Inputs
        std::string message("Bgc-bfufb tegaedppqna ql aggv zge xof tegaedppfe'l lgjb.\n"
                                                "Xof adpf vflqanfe logjbvn'x hf pdwqna d cgebv qn coqro xof tbdkfe ql mjlx d lpdbb tdex. Xof tbdkfe QL XOF\n"
                                                "HGLL; qx'l kgje vjxk xg fnxfexdqn oqp ge ofe.\n"
                                                "Zgrjl ql d pdxxfe gz vfrqvqna codx xoqnal kgj def ngx agqna xg vg.\n"
                                                "Xof rglx gz dvvqna d zfdxjef qln'x mjlx xof xqpf qx xdwfl xg rgvf qx. Xof rglx dblg qnrbjvfl xof dvvqxqgn gz\n"
                                                "dn ghlxdrbf xg zjxjef fstdnlqgn. Xof xeqrw ql xg tqrw xof zfdxjefl xodx vgn'x zqaox fdro gxofe. - Mgon\n"
                                                "Rdepdrw.\n"
                                                "(ccc.adpdljxed.rgp/uqfc/nfcl/234346?utkjpvbjr)\n"
                                                "(ccc.hedqnkijgxf.rgp/ijgxfl/djxogel/m/mgon_rdepdrw.oxpb)");
                      
        std::string freqLang ("TEOAISRHNUCMDLGWFPYKJBVQX");
        std::string alphabet ("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
        std::vector<int> myFreq (alphabet.length() , 0);


    // Counting letters

        char auxChar{};

        for (char c : message)
        {
                auxChar = toupper(c);
                switch(auxChar)
                
                {
                case 'A':
                    myFreq.at(0) += 1;
                    break;
                case 'B':
                    myFreq.at(1) += 1;
                    break;
                case 'C':
                    myFreq.at(2) += 1;
                    break;
                case 'D':
                    myFreq.at(3) += 1;
                    break;
                case 'E':
                    myFreq.at(4) += 1;
                    break;
                case 'F':
                    myFreq.at(5) += 1;
                    break;
                case 'G':
                    myFreq.at(6) += 1;
                    break;
                case 'H':
                    myFreq.at(7) += 1;
                    break;
                case 'I':
                    myFreq.at(8) += 1;
                    break;
                case 'J':
                    myFreq.at(9) += 1;
                    break;
                case 'K':
                    myFreq.at(10) += 1;
                    break;
                case 'L':
                    myFreq.at(11) += 1;
                    break;
                case 'M':
                    myFreq.at(12) += 1;
                    break;
                case 'N':
                    myFreq.at(13) += 1;
                    break;
                case 'O':
                    myFreq.at(14) += 1;
                    break;
                case 'P':
                    myFreq.at(15) += 1;
                    break;
                case 'Q':
                    myFreq.at(16) += 1;
                    break;
                case 'R':
                    myFreq.at(17) += 1;
                    break;
                case 'S':
                    myFreq.at(18) += 1;
                    break;
                case 'T':
                    myFreq.at(19) += 1;
                    break;
                case 'U':
                    myFreq.at(20) += 1;
                    break;
                case 'V':
                    myFreq.at(21) += 1;
                    break;
                case 'W':
                    myFreq.at(22) += 1;
                    break;
                case 'X':
                    myFreq.at(23) += 1;
                    break;
                case 'Y':
                    myFreq.at(24) += 1;
                    break;
                case 'Z':
                    myFreq.at(25) += 1;
                    break;
                default:
                    break;
                }
        }


        // Sorting my vector and my alphabet-string using Selection Sort
        int auxNumber{};
        char auxCharacter{}; 

        for (size_t i{} ; i < alphabet.length() ; i++)
        {
                size_t index{i};

                for (size_t j{index + 1} ; j < alphabet.length() ; j++)
                {
                        if (myFreq.at(j) > myFreq.at(index))
                        index = j;
                }

                auxNumber = myFreq.at(i);
                auxCharacter = alphabet.at(i);
                myFreq.at(i) = myFreq.at(index);
                alphabet.at(i) = alphabet.at(index);
                myFreq.at(index) = auxNumber;
                alphabet.at(index) = auxCharacter;

        }


    //Setting up my code strings with lower case letters
        for (size_t a{} ; a < 25 ; a++)
                freqLang.push_back(tolower(freqLang.at(a)));

        alphabet.pop_back();

        for (size_t b{} ; b < 25 ; b++)
                alphabet.push_back(tolower(alphabet.at(b)));


        //Decoding my message
        std::string decoMessage{};
        size_t currentPos{};

        for (char c : message)
        {
                currentPos = alphabet.find(c);

                if (currentPos != std::string::npos)
                        c = freqLang.at(currentPos);
                
                decoMessage.push_back(c);
        }
    
    
        //Printing the decoded message
        std::cout << "The decoded message is: " << std::endl << std::endl;
    
        for (auto d : decoMessage)
                std::cout << d;
        
        std::cout << std::endl;

        return 0;
}
