using System;
using System.Collections.Generic;
using System.Linq;

namespace Kattis
{
    class AlphabetAnimals
    {
        static void Main(string[] args)
        {
            string keyword = Console.ReadLine();
            int numanimals = Convert.ToInt32(Console.ReadLine());
            string[] animals = new string[numanimals];

            // Frequency arrays
            int[] firstletters = new int[26];
            int[] lastletters = new int[26];

            // Reads in the list of animals
            for (int i = 0; i < numanimals; i++)
                animals[i] = Console.ReadLine();

            // Two frequency arrays that track the first and last letters
            // of every entered word
            for (int i = 0; i < animals.Length; i++)
            {
                firstletters[animals[i][0] - 97]++;
                lastletters[animals[i][animals[i].Length - 1] - 97]++;
            }

            // If there is no possible answer
            if (firstletters[(keyword[keyword.Length - 1]) - 97] == 0)
            {
                Console.WriteLine("?");
                return;
            }

            // This will track the possible correct answers
            List<string> validanimals = new List<string>();

            // Adds the possible answers to the list
            for (int i = 0; i < animals.Length; i++)
            {
                if (animals[i][0] == keyword[keyword.Length - 1])
                {
                    validanimals.Add(animals[i]);
                }
            }

            // Checks if any answers can win the game for the player
            foreach (string pwinner in validanimals)
            {
                firstletters[pwinner[0] - 97]--;
                if (firstletters[pwinner[pwinner.Length - 1] - 97] == 0)
                {
                    Console.WriteLine($"{pwinner}!");
                    return;
                }
                firstletters[pwinner[0] - 97]++;
            }

            // Print out the first animal if no animal can win the game for the player
            Console.WriteLine(validanimals.First());
        }
    }
}
