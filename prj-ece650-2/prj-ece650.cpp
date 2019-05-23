#include "VertexCoverAlgo.h"
#include "Graph.h"
#include <pthread.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <memory>
#include <unistd.h>
#include <bits/stdc++.h>

using namespace std;
static void *(* vcAlgo[])(void *) = {APPROX_VC_3, APPROX_VC_1,APPROX_VC_2};
static const char *algos[] = {"CNF-SAT-VC: ", "APPROX-VC-1: ", "APPROX-VC-2: "};

void findVertexCover(Graph &graph)
{
    pthread_t threads[3];
    VertexVec *output[3];
    int retCode;
    for(size_t i = 0; i < 3;++i) {
        retCode = pthread_create(&threads[i], nullptr, vcAlgo[i], &graph);
        if (retCode) _exit(1);
    }

    for(size_t i = 0; i < 3;++i) {
        pthread_join(threads[i],(void **)&output[i]);
        cout<<algos[i];
        if(!output[i]) continue;
        VertexVec &C = *output[i];
        
        for (unsigned j=0; j < C.size(); j++){
            cout<<C[j];
            if(j + 1 != C.size()){
                cout<<',';
            }
        }
        cout << endl;
    }


    for(size_t i = 0; i < 3;++i) {
        delete(output[i]);
    }
}

void *IOThread(void *){
    Graph &graph = *new Graph();
    char command;
    string line;
    unsigned int vertices = 0;
    string edgeString;
    char prevComm = '0';

    unsigned int V = 0;
    while (true)
    {
        std::string line;
     
        getline(std::cin, line);
        
        if (line == "")
        {
            break;
        }
        
        istringstream input(line);
        while (input >> command) {
            switch (command)
            {
                case 'V' :
                    if (prevComm == 'V')
                    {
                        cerr << "Error: V is repeated.\n";
                        break;
                    }
                    else
                    {
                        input >> vertices;
                        V = vertices;
                        graph.init(vertices);
                        prevComm = 'V';

                        break;
                    }


                case 'E' :
                {
                    unsigned int erroFlag = 0;
                    if ( prevComm == 'E')
                    {
                        cerr << "Error: E is repeated.\n ";
                        break;
                    }
                    else
                    {
                        input >> edgeString;
                        //std::cout<<"edge_string"<<edge_string<<std::endl;
                        
                        istringstream inputEdge(edgeString);
                        //std::cout<<"inout edge"<<input_edg<<std::endl;
                        char edgeChar;
                        unsigned int vertex= 0;
                        unsigned int v1;
                        unsigned int v2;

                        inputEdge >> edgeChar;//read '{'
                        //std::cout<<"edge char"<<edge_char<<std::endl;
                       //if(edge_char){
                        //std::cout<<"Edgechar"<<edge_char<<std::endl;
                        if(edgeChar == NULL){
                            erroFlag = 1;
                        } else {
                            
                        while (edgeChar != '}') {
                            inputEdge >> edgeChar;// read '<'
                            if (edgeChar == '}')
                            {
                                erroFlag = 1;
                                break;
                            }
                            else
                            {

                                inputEdge >> vertex;// read the first vertex
                                v1 = vertex;
                                inputEdge >> edgeChar;// read ','

                                inputEdge >> vertex;// read the second vertex
                                v2 = vertex;

                                inputEdge >> edgeChar;// read '>'
                                inputEdge >> edgeChar;// read ',' or '}'
//                                std::cout<<"v1 and v2 ="<<v1<<" "<<v2<<std::endl;
//                                std::cout<<"vertices num"<<vertices_num<<std::endl;
                                if(v1>=V || v2>=V){
//                                    std::cout<<"Error: Invalid Edge"<<std::endl;
                                    erroFlag = 1;
                                    //pre_cmd = 'E';
                                    break;
                                }
                                graph.add({v1,v2});
                                
                                
//                                if (v1 > vertices_num || v2 > vertices_num)
//                                {
//                                    std::cout<<"into out of range loop"<<std::endl;
//                                    cerr << "Error: point order out of range.\n";
//                                    break;
//                                }

                            }

                        }
                        }
                        if(erroFlag == 1)
                        {
                            prevComm = 'E';
                            std::cerr<<"Error: Invalid Edge"<<std::endl;
                            break;
                        } else {
                            //std::cout<<"into here 333"<<flagE<<std::endl;
/*                        for ( int i =0; i < Edges.size(); i++)
                        {
                            cout<<"i:"<<i<<"  "<<Edges[i].v1<<Edges[i].v2<<endl;
                        }*/
                        findVertexCover(graph);
                        
                        prevComm = 'E';
                        break;
                        }

                       }
//                       else {
//                           std::cerr<<"Error: blank Edge"<<std::endl;
//                       }
                }

            }

        }
        //}

    }
    //}
    return nullptr;

}

int main(int argc, char **argv)
{
    int retCode;
    pthread_t ioThread;
    //srand(time(nullptr)); // srand() in main functoin to ensure the unique random value of each time
    retCode = pthread_create(&ioThread, nullptr, IOThread, nullptr);
    if (retCode) return 1;
    retCode = pthread_detach(ioThread); // this line is used to make that when main thread finish, the iothread won't be blocked
    if (retCode) return 1;
    pthread_exit(0);
    return 1;
    
}















