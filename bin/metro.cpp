#include <stdio.h>
#include <assert.h>
#include <string>
#include <vector>
#include <algorithm>

#define MAXN 10000000

char forward[MAXN + 1], backward[MAXN + 1], observation[MAXN + 1];


size_t stringCount(const std::string& referenceString,const std::string& subString) {

    const size_t step = subString.size();

    size_t count(0);
    size_t pos(0);

    while ((pos = referenceString.find(subString, pos)) != std::string::npos) {
        ++pos;
        ++count;
    }

    return count;
}

int solve(int N, char forward[], char backward[], int M, char observation[]) {

    std::vector<char> inverseForward = std::vector<char>(forward, forward + N);
    std::vector<char> inverseBackward = std::vector<char>(backward, backward + N);
    std::reverse(inverseForward.begin(), inverseForward.end());
    std::reverse(inverseBackward.begin(), inverseBackward.end());

    for(int i = 0; i < M; i++)
    {
        if(observation[i] == '<')
        {
            observation[i] = '^';
        }
        else
        {
            observation[i] = 'V';
        }
    }

    std::string s(observation);
    std::string s1(forward);
    std::string s3(backward);
    std::string s2(inverseForward.begin(), inverseForward.end());
    std::string s4(inverseBackward.begin(), inverseForward.end());

    return static_cast<int>(stringCount(s1, s) + stringCount(s2, s) + stringCount(s3,s) + stringCount(s4,s));
}

int main() {
    FILE *fr, *fw;
    int N, M, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    assert(1 == fscanf(fr, "%s", forward));
    assert(1 == fscanf(fr, "%s", backward));
    assert(1 == fscanf(fr, "%d", &M));
    assert(1 == fscanf(fr, "%s", observation));

    fprintf(fw, "%d\n", solve(N, forward, backward, M, observation));
    fclose(fr);
    fclose(fw);
    return 0;
}
