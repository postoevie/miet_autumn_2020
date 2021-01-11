N = 10000;

G = grand(N, 1, "nor", 0, 1);
scf();
histplot(20,G);

boundary = sqrt(12) / 2
U = grand(N, 1, "unf", -boundary, boundary);
scf();
histplot(20, U);
