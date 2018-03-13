#include <iostream>
#include <vector>
 class Group{
 public:
     Group() {}
     int state;
     int size;
 };

std::vector<Group> groups;

std::vector<std::vector<std::vector<int> > > matrix;



std::vector<std::vector<std::vector<int> > > initialize_matrix(int num_groups,int max_changes){
    std::vector <int> change_vec((unsigned long)max_changes+1);
    for(int i = 0; i < max_changes;i++){
        change_vec[i] = 1501;
    }
    std::vector < std::vector <int> > group_vec((unsigned long)num_groups,change_vec);
    std::vector<std::vector<std::vector<int> > >m((unsigned long) 2,group_vec);



    for(int i = 0;i < 2;i++){
        std::cout << i << ": ";
        for(int j = 0; j < num_groups;j++){
            for(int k = 0; k < max_changes+1;k++){
                m[i][j][k] = 1501;
                std::cout << m[i][j][k] <<" ";
            }
            std::cout << "\n";
        }
    }
    return m;
}

int fertilize(int state,int n_group,int n_changes,int num_groups,int max_changes,std::vector<std::vector<std::vector<int> > >* m){
    if((*m)[state][n_group][n_changes] != 1501){
        std::cout << '['<< state << ','<<n_group << ',' << n_changes<<']' << "State already in the table: "<< (*m)[state][n_group][n_changes] << '\n';
        return (*m)[state][n_group][n_changes];
    }
    Group current = groups[n_group];
    if(n_group == num_groups -1){

        std::cout << '['<< state << ','<<n_group << ',' << n_changes<<']' << "Last group achieved!" << '\n';
        if(current.state == state){
            (*m)[state][n_group][n_changes] = 0;
        }else{
            (*m)[state][n_group][n_changes] = current.size;
        }
        std::cout << '['<< state << ','<<n_group << ',' << n_changes<<']' << "->" << (*m)[state][n_group][n_changes] << '\n';
        return (*m)[state][n_group][n_changes];
    }else{
        std::cout << '['<< state << ','<<n_group << ',' << n_changes<<']' << "State not in table!" << '\n';

        int wrong = ((state == current.state)? 0:current.size);
        int no_change = fertilize(state,n_group+1,n_changes,num_groups,max_changes,m);
        int change = 1501;
        if(n_changes < max_changes && current.state != groups[n_group+1].state){
            int new_state = ((current.state == 0)? 1:0);
            change = fertilize(new_state,n_group+1,n_changes+1,num_groups,max_changes,m);
        }else{
            std::cout << "No more changes allowed!\n";
        }
        (*m)[state][n_group][n_changes] = wrong + ((change > no_change)? no_change:change);
        std::cout << '['<< state << ','<<n_group << ',' << n_changes<<']' << "State calculated: "<<(*m)[state][n_group][n_changes] << '\n';

        std::cout << '['<< state << ','<<n_group << ',' << n_changes<<']' << "State already in the table: "<< (*m)[state][n_group][n_changes] << '\n';
        return (*m)[state][n_group][n_changes];
    }
}


int www(int num_groups,int max_changes){
    if(max_changes >= num_groups){
        return 0;
    }
    std::cout << "\n\n" <<"Numero de grupos: " << num_groups <<"\n\n";
    matrix = initialize_matrix(num_groups,max_changes);
    int start_1, start_2,new_state;
    Group first = groups[0];
    start_1 = fertilize(first.state,0,1,num_groups,max_changes,&matrix);
    std::cout << '['<< first.state << ','<< 0 << ',' << 1<<']' << "First with right state: "<< start_1 << '\n';
    new_state = ((first.state == 1)? 0:1);

    start_2 = fertilize(new_state,0,1,num_groups,max_changes,&matrix);
    std::cout << '['<< new_state << ','<< 0 << ',' << 1<<']' << "First with wrong state: "<< start_2 << " First size: "<< first.size<<'\n';
    return ((start_1 < start_2)? start_1: start_2);
}


void input(){
    std::string str;
    int  max_changes,num_groups;
    int best;
    while(std::getline (std::cin,str)){
        groups.clear();
        max_changes = 0;
        num_groups = 0;
        std::cout << str <<"\n";
        int i;
        for(i = 0; i<(int)str.size();i++){
            if(str[i]!=' '){
                max_changes = 10*max_changes + ((int)str[i]-48);
            }else break;
        }
        std::cout << "Numero de trocas permitidas: " << max_changes << "\n";
        int counter = 1;
        int state = str[i+1]-48;
        for(i= i+2;i<(int)str.size();i++){
            if(((int)str[i]-48) != state){
                Group r;
                r.size = counter;
                r.state = state;
                groups.push_back(r);
                std::cout << "Linha de tulipas num: " << state << " com "<< counter << "flores  \n";
                num_groups++;
                state = (int)str[i]-48;
                counter = 1;
            }else{
                counter++;
            }
        }
        Group r;
        r.size = counter;
        r.state = state;
        groups.push_back(r);
        num_groups++;
        std::cout << "Linha de tulipas num: " << state << " com "<< counter << "flores  \n";
        std::cout << " Numero total de grupos: " << num_groups <<"\n";
        best = www(num_groups,max_changes);
        std::cout << "Melhor possivel: " << best << '\n';
    }
}


int main() {

    std::cout << "Hello, World!" << std::endl;
    input();

    return 0;
}