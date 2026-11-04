/* FUN_80164e94
 * image   ovl_00a43b6 (ovl), base 0x80161cf0
 * address 0x80164e94  body 0x80164e94..0x80164feb  size 344 B
 * body sha256 203a02892c1640fbc51229549172b842ece90242e2da7117769cd0a8f8fafba0
 * provider record sha256 86b8770ecb87d082763c1e1cc3a92f51624db979c6f41bd0b5447baed7be64e0
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164e94(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  short sVar4;
  uint uVar2;
  int iVar3;
  ushort uVar5;
  
  bVar1 = *(byte *)(param_1 + 6);
  *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        *(undefined2 *)(param_1 + 0x1f2) = 0xffff;
        *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) | 0x4000;
        return;
      }
      if (bVar1 == 3) {
        *(undefined2 *)(param_1 + 500) = 10;
        return;
      }
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined4 *)(param_1 + 0x1e8) = 0x10000000;
    func_0x80089d54(param_1,param_2,param_3,0x100);
    *(undefined2 *)(param_1 + 0x1f6) = 5;
    *(undefined1 *)(param_1 + 6) = 1;
    *(ushort *)(param_1 + 0x2b8) = *(ushort *)(param_1 + 0x2b8) | 1;
    *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) & 0xbfff;
  }
  sVar4 = *(short *)(param_1 + 0x1f6) + -1;
  *(short *)(param_1 + 0x1f6) = sVar4;
  if (sVar4 == -1) {
    uVar2 = func_0x80033604();
    iVar3 = ((uVar2 & 0xff) % 3) * 4;
    *(int *)(param_1 + 0x28) = (int)*(short *)(&DAT_80169894 + iVar3);
    *(int *)(param_1 + 0x30) = (int)*(short *)(&DAT_80169896 + iVar3);
    uVar5 = func_0x80033604();
    *(ushort *)(param_1 + 0x1f6) = (uVar5 & 0xf) + 0xf;
    uVar5 = func_0x80033604();
    *(ushort *)(param_1 + 0x66) = (uVar5 & 0xff) << 4;
  }
  return;
}
