/* FUN_800ab43c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ab43c  body 0x800ab43c..0x800ab503  size 200 B
 * body sha256 36fe1f39dbf152d6d779c5c5046a7036e00a215046758b9c7f068b7e2c24b9b8
 * provider record sha256 e716025f46e3e2a98f4c2b7bb6d4dead5e43140bbcf9d4d6f1172d618b5cf41b
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int FUN_800ab43c(undefined4 param_1,int param_2,int param_3,int param_4,code *param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (param_3 != 0) {
    iVar5 = 1;
    iVar1 = param_3 + 1;
    do {
      iVar4 = (iVar1 >> 1) + -1;
      iVar3 = param_2 + param_4 * iVar4;
      iVar2 = (*param_5)(param_1,iVar3);
      if (iVar2 == 0) {
        return iVar3;
      }
      if (-1 < iVar2) {
        iVar5 = (iVar1 >> 1) + 1;
        iVar4 = param_3;
      }
      iVar1 = iVar5 + iVar4;
      param_3 = iVar4;
    } while (iVar5 <= iVar4);
  }
  return 0;
}
