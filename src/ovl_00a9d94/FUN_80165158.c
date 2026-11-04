/* FUN_80165158
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x80165158  body 0x80165158..0x80165287  size 304 B
 * body sha256 fd6c0ef72a65f6c1b6e6f9561524bcc668d8ecfd316c95f3a30ab37b9103d6ed
 * provider record sha256 8dfbefd5b19d407783063f6466c6018a859abe55c2ab2262fd3e2f5099d3e874
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165158(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  ushort uVar5;
  
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 != 2) {
        return;
      }
      *(undefined4 *)(param_1 + 4) = 0x1030000;
      *(undefined1 *)(param_1 + 0x2ce) = 0x5a;
      if ((*(ushort *)(param_1 + 0x2b6) & 2) == 0) {
        return;
      }
      uVar3 = func_0x80033604();
      if ((uVar3 & 3) == 0) {
        *(undefined4 *)(param_1 + 4) = 0x10a0000;
        return;
      }
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined4 *)(param_1 + 0x1e8) = 0xf020300;
    uVar5 = *(ushort *)(param_1 + 0x2b6) & 0xff43;
    *(undefined1 *)(param_1 + 6) = 1;
    *(ushort *)(param_1 + 0x2b6) = uVar5;
    if (*(short *)(param_1 + 0x25e) == -0xe10) {
      uVar4 = 4;
      *(ushort *)(param_1 + 0x2b6) = uVar5 | 0x20;
      *(undefined2 *)(param_1 + 0x136) = 500;
      *(undefined2 *)(param_1 + 0x138) = 500;
      *(undefined2 *)(param_1 + 300) = 500;
      *(undefined2 *)(param_1 + 0x12e) = 500;
    }
    else {
      uVar4 = 3;
    }
    func_0x80077d18(uVar4,param_1);
    func_0x80052c6c(8,100,0);
  }
  iVar2 = func_0x80089d54(param_1,param_2,param_3,0x400);
  if (iVar2 != 0) {
    *(undefined1 *)(param_1 + 6) = 2;
  }
  return;
}
