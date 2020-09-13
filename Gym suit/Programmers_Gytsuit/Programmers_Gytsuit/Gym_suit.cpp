#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int Gym_suit[31];
    int left = 0, right = 0;
    
    for (int i = 0; i < n; i++)
        Gym_suit[i] = 1;

    for (int i = 0; i < lost.size(); i++)
    {
        Gym_suit[lost[i]-1]--;
    }

    for (int i = 0; i < reserve.size(); i++)
    {
        Gym_suit[reserve[i] - 1]++;
    }
    
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            if (Gym_suit[i] == 2 && Gym_suit[i + 1] == 0)
            {
                Gym_suit[i] = 1;
                Gym_suit[i + 1] = 1;
            }
        }
        if (Gym_suit[i] == 0)
        {
            if (Gym_suit[i - 1] == 2)
            {
                Gym_suit[i]++;
                Gym_suit[i - 1]--;
            }
            else if (Gym_suit[i + 1] == 2)
            {
                Gym_suit[i]++;
                Gym_suit[i + 1]--;
            }

        }
    }

    for (int i = 0; i < n; i++)
    {
        if (Gym_suit[i] >= 1)
        {
            answer++;
        }
    }
    return answer;
}

/*5	[2, 4]	[1, 3, 5]*/
int main() {
    cout << solution(5, { 2, 4 }, { 3}) << '\n';
}
