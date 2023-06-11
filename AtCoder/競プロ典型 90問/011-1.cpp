#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


class Job {
    public:
        Job(long D, long C, long S);
        long D;
        long C;
        long S;
        bool operator==(const Job& other) const;
        bool operator<(const Job& other) const;
        long stard_deadline();
};

Job::Job(long D_, long C_, long S_) {
    this -> D = D_;
    this -> C = C_;
    this -> S = S_;
};

long Job::stard_deadline() {
    return D-C;
}

bool Job::operator==(const Job& other) const {
    return (D==other.D)&&(C==other.C)&&(S==other.S);
};
bool Job::operator<(const Job& other) const {
    if(D!=other.D){
        return D<other.D;
    }
    else if(C!=other.C){
        return C<other.C;
    }
    else{
        return S<other.S;
    }
};

long Reward(vector<Job> v);

int main(void) {
    long N;
    cin>>N;
    vector<Job> v;
    v.clear();
    for(long i=0;i<N;i++) {
        long D,C,S;
        cin>>D>>C>>S;
        Job* job = new Job(D,C,S);
        v.push_back(*job);
    }
    sort(v.begin(), v.end());
    long retval= 0;
    for(long i=0;i<pow(2,N);i++) {
        long j = i;
        vector<Job> jobs;
        jobs.clear();
        int index = 0;
        while(j>0) {
            if(j%2==1){
                jobs.push_back(v[index]);
            }
            index++;
            j = j/2;
        }
        retval = max(retval, Reward(jobs));
    }
    cout<<retval<<endl;

}

long Reward(vector<Job> v){
    long today = 0;
    long reward = 0;
    for(Job job : v) {
        if(today>job.stard_deadline()){
            return -1;
        }
        reward += job.S;
        today += job.C;
    }
    return reward;
}