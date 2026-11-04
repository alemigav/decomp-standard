/* FUN_8005de80
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005de80  body 0x8005de80..0x8005df97  size 280 B
 * body sha256 0ee14885182db7540e107f6159bbe93afa6fd151bb32af11825fabf6d076628b
 * provider record sha256 78b31c1afbdb56806df254dbf5e06451842c77f48c831ebad0c49fa68c21959d
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005de80(int param_1)

{
  char cVar1;
  int iVar2;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  
  cVar1 = *(char *)(param_1 + 0x1e9);
  if (cVar1 == '\x01') {
    local_18 = 0x6e;
    local_16 = 0x29e;
    local_14 = 0xfff6;
    iVar2 = *(int *)(param_1 + 0x234) + 0x1060;
    FUN_80037780(0x30a1400,0,iVar2,&local_18);
    FUN_80037780(0x1001d00,0,iVar2,&local_18);
    cVar1 = *(char *)(param_1 + 0x1e9);
  }
  if (cVar1 == '\x04') {
    local_18 = 0x14a;
    local_16 = 0x32;
    local_14 = 0;
    iVar2 = *(int *)(param_1 + 0x234) + 0x1060;
    FUN_80037780(0x3080900,0,iVar2,&local_18);
    FUN_80037780(0x3080900,0,iVar2,&local_18);
    FUN_80037780(0x2000900,(int)((DAT_800e1196 + 0x694) * 0x10000) >> 0x10,iVar2,&local_18);
  }
  return;
}
