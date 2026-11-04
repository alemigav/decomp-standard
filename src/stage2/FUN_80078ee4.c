/* FUN_80078ee4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80078ee4  body 0x80078ee4..0x80078fbf  size 220 B
 * body sha256 375cf59e8af9ec3287736d339938ed867766f362b97b3e27c8e9a6fd5fb72f93
 * provider record sha256 aae55588a338bc36f39d673a126e2a3652a1e01f8ac908bbf042cc2494310756
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80078ee4(short param_1,undefined4 param_2,uint param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = param_1 * 0x3c;
  if ((&DAT_8011a3a4)[iVar2] != '\0') {
    iVar4 = 0;
    iVar3 = iVar2;
    do {
      if (*(int *)((int)&DAT_8011a390 + iVar3) == 0) {
        return;
      }
      cVar1 = FUN_800a21a8(*(undefined4 *)((int)&DAT_8011a380 + iVar3));
      if (cVar1 != '\0') {
        FUN_800a2218(0,(param_3 & 0xfff) << 4,*(undefined4 *)((int)&DAT_8011a380 + iVar3),1);
        (&DAT_8011a3a4)[iVar2] = 1;
      }
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 4;
    } while (iVar4 < 4);
  }
  return;
}
