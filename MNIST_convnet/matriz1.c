
// C# program to multiply two matrices

using System;

class GFG {

        static int R1 = 2; // number of rows in Matrix-1
        static int C1 = 3; // number of columns in Matrix-1
        static int R2 = 3; // number of rows in Matrix-2
        static int C2 = 2; // number of columns in Matrix-2

        // This function multiplies mat1[][]
        // and mat2[][], and stores the result
        // in res[][]
        static void mulMat(int[, ] mat1, int[, ] mat2)
        {
                // To store result
                int[, ] rslt = new int[R1, C2];
                Console.WriteLine(
                        "Multiplication of given two matrices is:");
                int i, j, k;
                for (i = 0; i < R1; i++) {
                        for (j = 0; j < C2; j++) {
                                rslt[i, j] = 0;
                                for (k = 0; k < R2; k++)
                                        rslt[i, j] += mat1[i, k] * mat2[k, j];
                                Console.Write(rslt[i, j] + "\t");
                        }
                        Console.WriteLine();
                }
        }

        // Driver code
        public static void Main()
        {
                int[, ] mat1 = { { 1, 2,3 },
                                {4,5,6 } };

                int[, ] mat2 = { {7, 8 },
                                { 9, 10},
                                {11, 12} };

                 in Matrix-1 must be equal to the number of rows in Matrix-2");
                        Console.WriteLine(if (C1 != R2) {
                        Console.WriteLine(
                                "The number of columns
                                "Please update MACROs according to your array dimension in #define section");
                }
                else {
                        mulMat(mat1, mat2);
                }
        }
}


