/* FUN_800ae3d0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ae3d0  body 0x800ae3d0..0x800ae4d7  size 264 B
 * body sha256 85ee63a48e9da1b8fcf231396bed959ff990faca14b32e713f1006c54cab23b4
 * provider record sha256 6d3da90475af135ef8bb713f9b20177d2cf238ae75a4f93ac37b25a182043da7
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800ae3d0(int param_1)

{
  int iVar1;
  int iVar2;
  ushort *puVar3;
  byte *pbVar4;
  
  iVar1 = (uint)*(byte *)(param_1 + 99) * 4;
  pbVar4 = (byte *)(iVar1 + -0x7fea77c0);
  if (*(short *)(&DAT_80158842 + iVar1) == 1) {
    if (*pbVar4 == 0xff) {
      *(undefined1 *)(*(byte *)(param_1 + 0x2e) + 0x80158940) = *(undefined1 *)(iVar1 + -0x7fea77bf)
      ;
    }
    else {
      *(undefined1 *)((uint)*pbVar4 * 4 + -0x7fea77bf) = *(undefined1 *)(iVar1 + -0x7fea77bf);
    }
    if (*(byte *)(iVar1 + -0x7fea77bf) == 0xff) {
      if (*pbVar4 != 0xff) {
        *(undefined2 *)(&DAT_80158842 + iVar1) = 0;
        return;
      }
      iVar2 = (uint)*(byte *)(param_1 + 0x2e) * 4;
      puVar3 = (ushort *)(iVar2 + -0x7fea7bc8);
      if (*(ushort *)(iVar2 + -0x7fea7bc6) == 0xffff) {
        _DAT_8015883a = *puVar3;
      }
      else {
        *(ushort *)((uint)*(ushort *)(iVar2 + -0x7fea7bc6) * 4 + -0x7fea7bc8) = *puVar3;
      }
      if (*puVar3 != 0xffff) {
        *(undefined2 *)((uint)*puVar3 * 4 + -0x7fea7bc6) = *(undefined2 *)(iVar2 + -0x7fea7bc6);
      }
    }
    else {
      *(byte *)((uint)*(byte *)(iVar1 + -0x7fea77bf) * 4 + -0x7fea77c0) = *pbVar4;
    }
    *(undefined2 *)(&DAT_80158842 + iVar1) = 0;
  }
  return;
}
