from typing import List


class Solution:
    def minNumberOfHours(self, initialEnergy: int, initialExperience: int, energy: List[int],
                         experience: List[int]) -> int:
        sm = sum(energy)
        trainingHours = 0 if initialEnergy > sm else sm + 1 - initialEnergy
        for e in experience:
            if initialExperience <= e:
                trainingHours += 1 + (e - initialExperience)
                initialExperience = 2 * e + 1
            else:
                initialExperience += e
        return trainingHours


def main():
    initialEnergy = 7
    initialExperience = 1
    energy = [4, 3, 1]
    experience = [2, 1, 3]

    solution = Solution()
    min_hours = solution.minNumberOfHours(initialEnergy, initialExperience, energy, experience)
    print(f"Minimum number of training hours needed: {min_hours}")


if __name__ == '__main__':
    main()
