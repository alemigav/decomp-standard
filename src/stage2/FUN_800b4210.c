/* FUN_800b4210
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b4210  body 0x800b4210..0x800b431b  size 268 B
 * body sha256 c15988594eda9b51ec36d0924c7ccb7f90efd42c07c5b7beb454bd9634a91146
 * provider record sha256 7b679433e968f73611077434d39f1822542422ed583b45ae5b44398adf1eb70e
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800b4210(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar3 = 0;
  do {
    FUN_800b398c(iVar3);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 2);
  do {
    iVar1 = 0;
    iVar3 = -0x7fea74e0;
    do {
      if (*(char *)(iVar3 + 0x1200) != '\0') break;
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 0x1228;
    } while (iVar1 < 2);
    if (iVar1 == 2) {
      DAT_80136d80 = 0;
      FUN_800a5678();
      _DAT_80143fd8 = 0;
      FUN_800b480c();
      FUN_800a56c0();
      if ((_DAT_8015af7c != 0) && (DAT_80136d81 != '\0')) {
        (*_DAT_8014400c)();
      }
      iVar3 = 0;
      if ((_DAT_8015af90 & 1) != 0) {
        puVar4 = (undefined4 *)&DAT_8015af88;
        do {
          uVar2 = *puVar4;
          puVar4 = puVar4 + 1;
          iVar3 = iVar3 + 1;
          (*_DAT_8014400c)(uVar2);
        } while (iVar3 < 2);
      }
      return;
    }
  } while( true );
}
