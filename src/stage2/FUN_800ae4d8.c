/* FUN_800ae4d8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ae4d8  body 0x800ae4d8..0x800ae6b3  size 476 B
 * body sha256 b4f929122093ba582c1c6d2706032ab8033b55e6aeffb8aa0c9f3525a06a9703
 * provider record sha256 0f48ff13cfa38ab952c099af631e4362fbb8fbf1f6babd7d6bb3e153ec552057
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800ae4d8(int param_1,byte param_2)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  uint unaff_s3;
  
  bVar1 = *(byte *)(param_1 + 99);
  iVar3 = (uint)bVar1 * 4;
  if (*(short *)(&DAT_80158842 + iVar3) == 1) {
    if (*(byte *)(param_1 + 0x2e) == param_2) {
      return;
    }
    FUN_800ae3d0();
  }
  *(undefined1 *)(iVar3 + -0x7fea77c0) = 0xff;
  uVar6 = (uint)param_2;
  *(undefined2 *)(&DAT_80158842 + iVar3) = 1;
  bVar2 = *(byte *)(uVar6 + 0x80158940);
  *(byte *)(iVar3 + -0x7fea77bf) = bVar2;
  if (bVar2 == 0xff) {
    uVar5 = (uint)_DAT_8015883a;
    if (uVar5 == 0xffff) {
      *(ushort *)(uVar6 * 4 + -0x7fea7bc8) = _DAT_8015883a;
      *(ushort *)(uVar6 * 4 + -0x7fea7bc6) = _DAT_8015883a;
      _DAT_8015883a = (ushort)param_2;
    }
    else {
      uVar4 = (ushort)param_2;
      if (param_2 < uVar5) {
        uVar5 = (uint)_DAT_8015883a;
        *(ushort *)(uVar6 * 4 + -0x7fea7bc8) = _DAT_8015883a;
        *(undefined2 *)(uVar6 * 4 + -0x7fea7bc6) = 0xffff;
        _DAT_8015883a = uVar4;
        *(ushort *)(uVar5 * 4 + -0x7fea7bc6) = uVar4;
      }
      else {
        do {
          uVar6 = uVar5;
          uVar5 = uVar6;
          if (param_2 < uVar6) break;
          uVar5 = (uint)*(ushort *)(uVar6 * 4 + -0x7fea7bc8);
          unaff_s3 = uVar6;
        } while (uVar5 != 0xffff);
        *(ushort *)((unaff_s3 & 0xffff) * 4 + -0x7fea7bc8) = uVar4;
        *(short *)((uint)param_2 * 4 + -0x7fea7bc6) = (short)unaff_s3;
        *(short *)((uint)param_2 * 4 + -0x7fea7bc8) = (short)uVar5;
        if (uVar5 != 0xffff) {
          *(ushort *)(uVar5 * 4 + -0x7fea7bc6) = uVar4;
        }
      }
    }
  }
  else {
    *(byte *)((uint)*(byte *)(uVar6 + 0x80158940) * 4 + -0x7fea77c0) = bVar1;
  }
  *(byte *)(param_2 + 0x80158940) = bVar1;
  *(byte *)(param_1 + 0x2e) = param_2;
  return;
}
