/* FUN_800b40c4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b40c4  body 0x800b40c4..0x800b420f  size 332 B
 * body sha256 face941eced547b5ec2e934d5d21262ea62fe54739a289dbc218c41296d9fdb5
 * provider record sha256 a65ac47d1b2109f0a5c556ab9f5d06b781dd6e76bea1cbac491a5f5a0a0d3194
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800b40c4(uint param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  
  iVar5 = 0;
  iVar3 = -0x7fea74e0;
  _DAT_8015af7c = 0;
  _DAT_8015af90 = param_1;
  do {
    FUN_800b4930(iVar3,0,0,0,0);
    if (DAT_80143fe8 != '\0') {
      *(char *)(iVar3 + 0x11de) = *(char *)(iVar3 + 0x11de) << 1;
    }
    *(undefined1 *)(iVar3 + 0x1200) = 0;
    iVar5 = iVar5 + 1;
    iVar3 = iVar3 + 0x1228;
  } while (iVar5 < 2);
  osCreateMesgQueue(0x8015afa0,0x8015afb8,1);
  osSendMesg(0x8015afa0,0,0);
  if ((_DAT_8015af90 & 1) != 0) {
    uVar1 = FUN_800a9420(0x10e0);
    iVar3 = 0;
    puVar4 = (undefined4 *)&DAT_8015af88;
    do {
      iVar3 = iVar3 + 1;
      uVar2 = (*_DAT_80144008)(uVar1,0);
      *puVar4 = uVar2;
      func_0x80007320(uVar2,uVar1);
      puVar4 = puVar4 + 1;
    } while (iVar3 < 2);
  }
  _DAT_80143fd8 = func_800b3b9c;
  DAT_80136d80 = 1;
  _DAT_8015af70 = 0;
  return;
}
