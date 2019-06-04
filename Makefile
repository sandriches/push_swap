# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rcorke <rcorke@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/05/01 19:10:09 by rcorke         #+#    #+#                 #
#    Updated: 2019/06/04 12:47:06 by rcorke        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME= push_swap
SOURCES= tester_push_swap.c do_ops.c libft/libft.a libftprintf.a

all:
	gcc -g -Wall -Wextra $(SOURCES) -o $(NAME)
	./push_swap 9848	9500	-1420	5987	-4322	-8611	5919	-6290	-7647	7699	5414	-6088	1672	-2804	-7748	-8609	-1527	1539	-4042	6871	-1967	5505	6980	-4548	-2454	-560	-9270	-9673	6212	937	3694	-1616	-9665	-8505	8632	-7665	4608	-6482	-1251	5656	-2887	1399	-6988	4607	9230	8248	3257	-4444	-6523	4928	-1346	-7014	6333	-6319	-4889	516	-8923	-3817	-5081	-1607	2409	9466	-8492	1831	-1811	896	-752	8804	-1381	751	981	5365	2514	-857	-4825	7706	3714	-380	6673	6381	3165	-1444	8948	827	6199	-8081	8251	5990	351	6729	-4840	-8454	3649	53	-7587	-8085	-1752	-7722	5123	4888	-2147	-8606	2570	3675	1575	8121	-4882	-7537	-8216	9941	8353	6074	-134	-3126	-8858	3910	-2829	4284	-8519	-783	-6826	-342	5896	7751	6006	-3578	9480	7785	-6708	-8415	-4071	518	2901	6562	5699	7147	-8811	-2543	4381	-1937	-1958	9593	-7133	7021	-3661	-890	7236	887	-5509	-561	-6521	3930	-6288	-8801	-2181	5008	-8846	-6812	7069	865	5016	7439	4060	-7943	-7478	-9498	6204	-1503	-2660	8519	389	4193	7163	-8468	5454	-9957	7087	-7926	-2730	7935	5693	9270	-1851	1101	6177	-2869	-4055	6458	6012	6344	-6337	9854	8174	1007	5632	-6760	5194	-2789	-399	4803	-3016	-5211	-5727	-4902	3475	-1392	-9877	6057	-939	8981	-6920	8728	7373	9227	-3755	-1324	-4340	1815	-3484	-7328	-3964	-6537	-9390	-680	-2349	-1690	106	-1606	-2487	2313	1644	-2096	-3787	1615	-4507	5434	5188	-9366	-8689	-6327	-8794	6747	6690	732	5280	1525	8973	-5328	4317	2835	97	-3402	-289	-379	-4411	-5575	-4398	-1344	-9797	-8539	-4545	7566	-7559	9364	-1133	4474	608	-8526	-5020	-9585	3801	6929	770	-3096	-8009	-8286	-8744	-9657	7613	3259	8433	-2325	-6815	-8865	-132	-8739	-8447	-4692	-7723	9917	7819	-6782	2321	-8603	1099	9950	-9349	-1951	-9805	-9443	6807	843	-1445	-6894	-1395	-2356	2167	3781	8560	6912	9355	2061	-653	-8573	4246	-7066	-4832	5924	-3269	-5443	-6662	9255	-5324	1836	-3117	388	-5065	2102	592	2712	8320	4765	-6979	-5571	-9313	7319	-8105	9294	-4206	1825	-5970	3867	-5140	5447	-9673	-7024	7438	-9549	7830	6005	-9655	1361	-8550	5113	5579	4572	8755	5682	-7890	-5251	4334	-8313	7035	-2120	8354	-316	-7867	-8617	9963	6932	6095	7930	-2491	-4811	3858	-838	-8474	-8341	6821	-1399	-1958	-1130	-1366	-642	6990	-4504	1597	5099	-4246	-3620	-823	6454	9592	-1668	5231	7107	-3217	7954	-5110	-4034	9696	5434	-5424	5406	5777	6548	1370	5804	5596	9137	-1069	-1433	7511	150	9386	-2599	9316	-4433	-5907	102	-9765	4505	4500	-8641	4574	-4873	-2135	-3532	-4020	1331	8939	2717	-2481	-1880	3437	-9411	9644	7397	9847	3078	3894	-5467	6421	6555	5232	9372	5723	-7185	8228	4301	6301	2224	9382	-4953	8836	7288	-142	-3003	3843	-4485	-8594	-6973	-6348	-4365	7273	9458	-4448	5025	2935	5673	6552	8484	-9430	6082	-9096	2185	8400	159	3646	-8636	1414	8408	7001	9298	-6753	-2773	-6890	-2413	-2519	1083	-4403	5503	9514	3009	-9952	9816	2803	-9868	-4605	2777
