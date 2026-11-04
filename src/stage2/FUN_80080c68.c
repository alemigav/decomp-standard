/* FUN_80080c68
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80080c68  body 0x80080c68..0x80080d63  size 252 B
 * body sha256 915b7efdc632d06974c2b1a2c4f5bed2b61cf4c036e6f4cf0184a960b150048b
 * provider record sha256 cc9ba878c6af5b22796843e7f700914eade33e5cc7b7ebb007458156f2eba9a2
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
int FUN_80080c68(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  ushort *puVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar6 = 0;
  iVar7 = 0;
  iVar5 = 2;
  puVar3 = &DAT_8011b560;
  piVar4 = &DAT_8011b54c;
  do {
    iVar2 = *piVar4;
    if (iVar2 == 0) break;
    iVar1 = FUN_80032e74(param_1,*(undefined4 *)(iVar2 + 0x28),*(undefined4 *)(iVar2 + 0x30),0x400);
    if (iVar1 == 0) {
      if (*puVar3 < 0x7fffffff) {
        iVar6 = iVar2;
      }
    }
    else if (*puVar3 < 0x7fffffff) {
      iVar7 = iVar2;
    }
    puVar3 = puVar3 + 1;
    iVar5 = iVar5 + -1;
    piVar4 = piVar4 + 1;
  } while (iVar5 != -1);
  if (iVar6 == 0) {
    iVar6 = iVar7;
  }
  return iVar6;
}
