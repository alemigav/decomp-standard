/* FUN_801632d4
 * image   ovl_00b08a2 (ovl), base 0x80161cf0
 * address 0x801632d4  body 0x801632d4..0x801634ab  size 472 B
 * body sha256 e6a29071ebd135ef1f22567b3b81ffde1f1f98d8f1439d12c642cc81197d7812
 * provider record sha256 297ab2d548dfb3baf0344fa53fea64fe80546813e3c704038db0b7fc9df5f570
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801632d4(int param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar3;
  uint uVar1;
  uint uVar2;
  ushort uVar4;
  
  if (*(char *)(param_1 + 6) == '\0') {
    uVar1 = func_0x80033604();
    uVar2 = func_0x80033604();
    *(undefined1 *)(param_1 + 6) = 1;
    *(uint *)(param_1 + 0x1e8) =
         ((uVar1 & 3) + 9) * 0x1000000 + ((uVar2 & 0xff) % 0x5a) * 0x10000 + 0x3f00;
    uVar4 = func_0x80033604();
    *(ushort *)(param_1 + 0x1f6) = (uVar4 & 0xf) + 0x3c;
    *(undefined1 *)(param_1 + 0x206) = 3;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  FUN_80166704(param_1,*(undefined4 *)(_DAT_800e1364 + 0x50),*(undefined4 *)(_DAT_800e1364 + 0x54),8
              );
  func_0x80089d54(param_1,param_2,param_3,0x40);
  sVar3 = *(short *)(param_1 + 0x1f6) + -1;
  *(short *)(param_1 + 0x1f6) = sVar3;
  if (sVar3 == -1) {
    uVar1 = func_0x80033604();
    uVar2 = func_0x80033604();
    *(uint *)(param_1 + 0x1e8) =
         ((uVar1 & 0xff) % 3 + 9) * 0x1000000 + ((uVar2 & 0xff) % 0x5a) * 0x10000 + 0x3f00;
    uVar4 = func_0x80033604();
    *(ushort *)(param_1 + 500) = (uVar4 & 0xf) + 0x3c;
  }
  return;
}
