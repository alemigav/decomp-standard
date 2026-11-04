/* FUN_80096e74
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80096e74  body 0x80096e74..0x80096f67  size 244 B
 * body sha256 4a68d5414a06efe28dc3739e653460c43b5f3a817acef23880bcefb7f7384567
 * provider record sha256 91378aac36e3c22ded473cb0ecd9fa17b247aef0b6a3877ca24ab313b189048d
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80096e74(int param_1)

{
  undefined *puVar1;
  int iVar2;
  undefined2 *puVar3;
  int iVar4;
  
  iVar4 = 6;
  if (param_1 != 0) {
    iVar4 = 0x11;
  }
  puVar3 = (undefined2 *)(DAT_800c52dc + 0x3bbfe);
  puVar1 = &UNK_8013129c + iVar4 * 4;
  iVar2 = DAT_800c52dc + 0x3bbf4;
  do {
    iVar4 = iVar4 + -1;
    FUN_80047b04(iVar2,0);
    FUN_8004786c(iVar2,0x80,0x80,0x80);
    FUN_800478ac(iVar2,puVar1[-4],puVar1[-3]);
    FUN_800479bc(iVar2,puVar1[-2],puVar1[-1]);
    *(undefined **)(puVar3 + 1) = &DAT_8012f530;
    *puVar3 = 0;
    puVar3 = puVar3 + 10;
    puVar1 = puVar1 + -4;
    iVar2 = iVar2 + 0x14;
  } while (iVar4 != 0);
  DAT_8012bfe4 = 7;
  DAT_8012bfe6 = 0x4e;
  return;
}
