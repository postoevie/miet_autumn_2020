clear;clc;
function Res = min_bd_stdfunc()
    Res = [1 1 1 2 1 1 2 1]';
endfunction
function Res = max_bd_stdfunc()
    Res = [2 2 2 3 2 2 3 2]';
endfunction
function Res = opti_stdfunc()
    Res = [1 3 2 2 1 3 2 3]';
endfunction
function Res = deshifrate(x)
    Res = x;
    //Работы 20, 25, 27 могут выполнятся на 1 и 3 станке, 
    // поэтому надо дешифровать
    // 2(20): 2->3 
    // 6(25): 2->3
    // 8(27): 2->3
    
    deshifr = [2, 6, 8];
    for i=1:length(deshifr)
        if (Res(deshifr) == 2)
            Res(deshifr) = 3;
        end
    end
endfunction
function Y = sumWorkByStanok(x)
    Z = [11 7 1000;
        //1000 12 1000;
          19 1000 8;
          8 5 1000;
        //  10 1000 1000;
          1000 6 11;
           7 18 1000;
           8 1000 14;
          1000 9 5;
          6 1000 11];
    //Так как числа генерируются в double, приводим к int
    x = int32(round(x));
    x = deshifrate(x);
    // Сумм. время работы каждого из станков
    // Так как 19 работа точно будет на 2 станке, а 22 на 1,
    // то сразу приплюсуем в соответствующую часть вектора Y
    Y = [10 12 0];

    for i=1:8
        Y(x(i)) = Y(x(i)) + Z(i, x(i));
    end
endfunction
function y = stdfunc(x)
    //Минимизируем среднеквадратичное отклонение
    y = stdev(sumWorkByStanok(x));
endfunction

func = 'stdfunc';
deff('y=f(x)','y = '+func+'(x)');

PopSize     = 1000;
Proba_cross = 0.7;
Proba_mut   = 0.1;
NbGen       = 10;
NbCouples   = 110;
Log         = %T;
nb_disp     = 10;
pressure    = 0.05;

ga_params = init_param();
// Параметры для задания области оптимизации
ga_params = add_param(ga_params, 'minbound', evstr('min_bd_'+func+'()'));
ga_params = add_param(ga_params, 'maxbound', evstr('max_bd_'+func+'()'));
ga_params = add_param(ga_params, 'dimension', 8);
ga_params = add_param(ga_params, 'beta', 0);
ga_params = add_param(ga_params, 'delta', 0.5);
// Параметры для настройки работы генетического алгоритма
ga_params = add_param(ga_params, 'init_func', init_ga_default);
ga_params = add_param(ga_params, 'crossover_func',crossover_ga_default);
ga_params = add_param(ga_params, 'mutation_func',mutation_ga_default);
ga_params = add_param(ga_params, 'codage_func',coding_ga_identity);
// selection_ga_default - не сущ
// elitist/random
ga_params = add_param(ga_params, 'selection_func',selection_ga_random);
ga_params = add_param(ga_params, 'nb_couples', NbCouples);
ga_params = add_param(ga_params, 'pressure', pressure);

[pop_opt, fobj_pop_opt, pop_init,fobj_pop_init]=...
optim_ga(f, PopSize, NbGen, Proba_mut, Proba_cross, Log, ga_params);

printf('Genetic Algorithm: %d points from pop_opt\n', nb_disp);
for i = 1:nb_disp
    printf('Individual %d: f = %f\n', i, fobj_pop_opt(i));
end
// находим минимум функции
[m, n] = min(fobj_pop_opt)
res = int32(round(pop_opt(n)));
Y = sumWorkByStanok(res);
res = deshifrate(res);
res = res';
