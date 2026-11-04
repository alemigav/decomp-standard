/* FUN_8016726c
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x8016726c  body 0x8016726c..0x80167373  size 264 B
 * body sha256 e91d99be24d10b9f62690e6848579e80c4c7d11bf3642ed327491f2ad06915e6
 * provider record sha256 8776128fec0b1b093c5f18d7d35f3f3716c410968bd00fbb93ed15774dbb4e5f
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016726c(int param_1,int param_2)

{
  byte bVar1;
  short sVar2;
  ushort uVar3;
  int iVar4;
  
  if (*(char *)(param_2 + 0x15) == '\0') {
    bVar1 = *(byte *)(param_2 + 0x14);
    if (bVar1 == 1) {
      sVar2 = *(short *)(param_2 + 0x16) + 0x200;
      *(short *)(param_2 + 0x16) = sVar2;
      if (0x2800 < sVar2) {
        *(undefined2 *)(param_2 + 0x16) = 0x2800;
        *(undefined1 *)(param_2 + 0x14) = 2;
      }
    }
    else if (bVar1 < 2) {
      if (bVar1 == 0) {
        *(undefined1 *)(param_2 + 0x14) = 1;
        *(undefined2 *)(param_2 + 0x16) = 0;
      }
    }
    else if ((bVar1 == 2) &&
            (uVar3 = *(short *)(param_2 + 0x16) - 0x800, *(ushort *)(param_2 + 0x16) = uVar3,
            (int)((uint)uVar3 << 0x10) < 0)) {
      *(undefined2 *)(param_2 + 0x16) = 0;
      *(undefined1 *)(param_2 + 0x14) = 1;
    }
    iVar4 = *(int *)(param_1 + 0x234);
    if (*(short *)(param_2 + 0x16) < 0x1000) {
      *(undefined2 *)(*(int *)(iVar4 + 0x410) + 0x10) = 0;
      *(short *)(*(int *)(iVar4 + 0x410) + 0x14) = 0x1000 - *(short *)(param_2 + 0x16);
    }
    else {
      *(short *)(*(int *)(iVar4 + 0x410) + 0x10) = *(short *)(param_2 + 0x16) + -0x1000;
      *(undefined2 *)(*(int *)(iVar4 + 0x410) + 0x14) = 0;
    }
    func_0x80066288(param_1);
  }
  return;
}
