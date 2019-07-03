# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rcorke <rcorke@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/05/01 19:10:09 by rcorke         #+#    #+#                 #
#    Updated: 2019/07/03 18:05:31 by rcorke        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME= push_swap
SOURCES= tester_push_swap.c do_ops.c libft/libft.a libftprintf.a ps_quicksort.c\
		ps_insertion_sort.c sort_4.c ps_find_median.c sort_6.c check_doubles.c \
		lookahead_functions.c sort_by_median.c find_biggest_or_smallest.c \
		sort_3_or_4_not_alone.c make_halving_array.c do_recursion.c \
		grab_4.c

all:
	gcc -g -Wall -Wextra $(SOURCES) -o $(NAME)
#500 ints
	# ./push_swap 4844	9749	9033	7002	4540	359	7066	3236	1480	2456	5761	8317	4936	2924	1614	8065	4797	1203	1678	9513	5925	4753	1580	1034	8639	1702	1993	8043	9763	2345	4670	6627	5730	2818	5429	675	7033	7198	830	3286	8088	1057	2470	6584	2625	2608	5217	2110	3127	1693	674	6454	2109	9954	5929	3478	9492	1421	1098	1847	5996	9601	3435	5934	8382	6677	4747	7383	4003	4832	2465	5918	2807	7717	8742	8947	4551	8172	3488	9091	6551	6375	4186	4024	1795	2676	93	9165	1685	1965	8789	4683	6195	1715	239	1056	9640	4260	9180	3301	619	5797	9297	7619	4929	4559	3790	6361	7230	238	7929	9302	6162	1774	5121	7908	9798	4649	8765	304	6367	6671	7566	9004	4312	1007	6344	1012	1875	9559	3979	8895	1853	8289	8304	493	4995	2176	4806	8957	3799	9985	8711	8365	9295	9476	9031	6659	3096	8528	5827	9914	9406	5570	9752	5015	2661	6858	2414	7268	9689	5603	7269	1547	9165	1366	1074	8021	4971	2223	3324	378	6051	7356	1155	2378	7949	76	9464	9864	9664	2375	309	1871	360	2823	9483	492	5131	2159	2433	3428	4026	3143	7066	6849	2826	324	4332	8788	1236	4316	2252	5558	545	7635	5380	1820	8760	2872	2356	8648	5623	5717	7029	6439	2513	3437	4969	9219	3043	461	1682	5876	9997	5633	8318	7328	6011	2085	4179	6813	372	6570	3741	4484	9564	4217	428	3192	6770	76	6564	5690	4379	3697	264	5860	1487	993	3399	4493	1905	1470	4444	7799	1889	5218	3285	1206	7895	5126	8877	3652	463	4901	6000	7779	3465	7723	1168	2382	3251	4009	754	7872	4258	1776	7596	5017	4841	2265	8571	6889	3012	5261	5336	4468	285	8942	8096	1253	6126	2362	9147	9396	7824	7704	4090	7945	2791	4130	6015	7429	2624	1488	8775	1636	1243	1966	3377	8956	9968	5238	331	2689	9495	5840	3395	3803	4959	723	812	5308	8497	4206	836	9959	2129	5317	7969	3734	2741	4971	7274	3612	4974	3427	2894	3100	2776	1570	3135	7534	9527	5086	4245	7620	9565	7030	9306	110	5511	473	4850	8939	5408	9939	1892	7729	9998	2609	422	6775	6580	9271	2222	3601	6568	6648	5201	4834	5272	303	8393	9536	5569	456	8224	394	1621	3476	8904	4388	5394	9834	8506	9144	9844	3309	8827	2385	485	6336	6280	4118	6133	4402	8091	8197	4464	2600	9640	4798	1492	8777	6542	5824	99	7956	7009	8510	9369	5910	6606	2260	170	4940	1481	1570	6844	682	6299	7124	3282	1208	4032	530	9357	7283	9787	6467	2523	5511	3065	1641	611	1818	3034	6050	1675	7420	5809	4918	1822	2060	2909	9903	7951	993	7843	3289	4862	6310	5534	9046	2274	8673	8752	9474	85	1840	6646	4812	5373	1156	9142	4028	3639	3827	3054	2597	5459	4215	6343	8775	7414	7072	9297	8506	5484	8769	4589	9774	4633	490	1809	1743	7442	2944	387	9639	4331	717	9926	479	3018	8561	7259	926

#200 ints
	# ./push_swap  10   63   16   70  107   81  168  142   96   60    8  126  127   50   66   40  112   62  181  164  186  172  143  195  110  132   46  198  183   92   90  124   55  196  193  179  166   97  113  123  199   56  192  103   48   80    1   19   23  170   20  153  137  184  200   58  180   29   79   57  100    6  144  182  173   52  109    9  165  106  116  191   31  139  121   30   22   89   64   42   39   37    2   44   78  138   51  115  194   91   95   17   25   26  119    5   11  152  117  141   98  136    3   82   38   68   33   75  161   36    7  135   83  159  171   15  104  108  140  197   73  145  157   34   32  185   35  167  146  148   65  158  178   12  134  129   41  149  176   59   84   53  177   71   99   93  174  190   43   14  131   28  105  154   49  155  151  156  120   94    4   74  188   77  133   67   85   72   87  102  163  128   45   27   13  130  175   47  147  114   24   88   69  187  118   76   21  101  125   18  150   61  189  122   54  162   86  111  169  160

#100 ints
	./push_swap 55	31	95	42	44	89	38	10	52	11	6	47	68	83	50	5	88	41	46	13	98	56	85	72	9	71	48	8	57	99	65	30	4	23	66	69	14	35	54	81	36	78	26	20	51	21	67	53	25	18	22	90	93	94	87	91	3	32	74	7	15	27	60	19	80	63	62	75	40	92	29	97	76	1	84	77	33	100	16	61	37	59	43	34	39	49	96	64	82	79	70	86	73	45	28	17	2	58	12	24

#100 ints
	# ./push_swap  70   89    5   69   71   14   11   96   19   93   40   45    3   57   56   25   72   43    8   51   80   87   44   85   60   62   98   21   64   67   10   26   81   55   48   38   13   23   61   20   77   58   95   75   74    1   37   68  100   41   66    6   47   97   76   24   86   32   54   92   31   35   52   84    7    9   27   29   12   73    4   30   46   49   33   16   59   65   34   88   83   90   79   17   22   42   36   15   91    2   63   53   82   94   50   18   78   99   39   28

#99 ints
	# ./push_swap 55	31	95	42	44	89	38	10	52	11	6	47	68	83	50	5	88	41	46	13	98	56	85	72	9	71	48	8	57	99	65	30	4	23	66	69	14	35	54	81	36	78	26	20	51	21	67	53	25	18	22	90	93	94	87	91	3	32	74	7	15	27	60	19	80	63	62	75	40	92	29	97	76	1	84	77	33	16	61	37	59	43	34	39	49	96	64	82	79	70	86	73	45	28	17	2	58	12	24

# 64 ints
	# ./push_swap 42 52	28	16	18	32	12	19	46	20	3 53 64	45	37	31	26	43	34	41	23	51	39 63	30	17	10	2	50	33	29	24 57	22	8 54 62	9	27	6 61	38	35 55	40	48	25	56 7	14	36 60	49	44	15	4	47	13	21 58	1	5	11 59

# 50 ints
	# ./push_swap  8  48   3  17  38   1  11  43  28   9  33  31  30  15  13  36  24  18  50  22   6  37  45  25   7   5  26  34  44  14  35  23  49  20  42  12  29  21  27  10  41   2  16  19  47  40  39  32  46   4

#6 ints
#	./push_swap 11 9 5 3 2 1


#	500

#	250		250		500
#	125		125		250
#	63		62		125
#	31		31		62
#	15		16		31
#	7		8		15
#	3		3		6

#	