//Atual do proximo do P2 vira o proximo do anterior do p1
  //Atual do anterior do p1 vira o anterior do proximo do p2

  int prevP1 = binarySearch(list, 13, PTR1.curr, 1) - 1;
  printf("v[%d] = %lx\n", prevP1, list[prevP1].curr);

  printf("%lx\n", PTR2.next);
  int nextP2 = binarySearch(v, 13, PTR2.curr, 1)+1;
  printf("v[%d] = %lx\n", nextP2, list[nextP2].curr);