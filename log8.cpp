#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#include <queue>

using namespace std;

void BFS(int s, int n, int* vis, int** G) {
    queue<int> q;  // ← ДОБАВЛЯЕМ локальную очередь
    vis[s] = 1;
    q.push(s);
    while (!q.empty()) {
        s = q.front();
        q.pop();
        printf("%d ", s);
        for (int i = 0; i < n; i++)
        {
            if (G[s][i] == 1 && vis[i] == 0)
            {
                q.push(i);
                vis[i] = 1;
            }
        }
    }
}

int main() {
    int n, m;
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");
    printf("Введите количество вершин для матрицы: ");
    scanf_s("%d", &n);

    // Проверка ввода
    if (n <= 0) {
        printf("Ошибка: количество вершин должно быть > 0\n");
        return 1;
    }

    int** G = new int* [n];
    int* vis = new int[n];
    for (int i = 0; i < n; i++)
    {
        G[i] = new int[n];
        vis[i] = 0;
    }

    // Генерация матрицы
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (i == j) {
                G[i][j] = 0;
            }
            else {
                G[i][j] = rand() % 2;
                G[j][i] = G[i][j];
            }
        }
    }

    printf("Матрица смежности:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", G[i][j]);
        }
        printf("\n");
    }

    printf("Введите номер стартовой вершины (0-%d): ", n - 1);
    scanf_s("%d", &m);

    // Проверка стартовой вершины
    if (m < 0 || m >= n) {
        printf("Ошибка: стартовая вершина должна быть в диапазоне 0-%d\n", n - 1);

        // Очистка памяти перед выходом
        for (int i = 0; i < n; i++) {
            delete[] G[i];
        }
        delete[] G;
        delete[] vis;

        return 1;
    }

    printf("Порядок обхода: ");
    BFS(m, n, vis, G); 

    // ОЧИСТКА ПАМЯТИ
    for (int i = 0; i < n; i++) {
        delete[] G[i];
    }
    delete[] G;
    delete[] vis;

    return 0;
}