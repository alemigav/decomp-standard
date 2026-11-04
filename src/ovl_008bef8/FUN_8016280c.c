/* FUN_8016280c
 * image   ovl_008bef8 (ovl), base 0x80161cf0
 * address 0x8016280c  body 0x8016280c..0x801629ff  size 500 B
 * body sha256 3cc04b7a3d961110c05ee078cc80c288621270dab53025917cfb769d978b0781
 * provider record sha256 874d8660964c2d11b8ac6f060c0ec6033fd18a5ec3a8a4a4a313168ca8463ac0
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016280c(int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  FUN_80162d84();
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        if (*(char *)(param_1 + 0x2c8) == '\0') {
          iVar2 = func_0x80036c68(param_1,3,0,0);
        }
        else {
          iVar2 = func_0x80036c68(param_1,3,0,0);
          iVar3 = func_0x80036c68(param_1,3,0,0);
          iVar2 = iVar2 + iVar3;
        }
        if (((*(char *)(param_1 + 0x2b6) == '\x02') && (*(char *)(param_1 + 0x1e8) == '\x03')) &&
           (0x71 < *(byte *)(param_1 + 0x1e9))) {
          *(ushort *)(param_1 + 0x2b4) = *(ushort *)(param_1 + 0x2b4) | 0x10;
        }
        if (iVar2 != 0) {
          *(undefined1 *)(param_1 + 0x2c1) = 0;
          *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + 0x400;
          if (*(char *)(param_1 + 0x2b6) == '\x02') {
            *(undefined4 *)(param_1 + 4) = 0x1070000;
            *(undefined1 *)(param_1 + 0x2ca) = 0xff;
          }
          else {
            *(undefined4 *)(param_1 + 4) = 0x1010000;
          }
        }
      }
      goto LAB_801629a4;
    }
    if (bVar1 != 0) goto LAB_801629a4;
    func_0x80077d18(4,param_1);
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
  }
  if (*(char *)(param_1 + 0x2c8) == '\0') {
    iVar2 = func_0x80036c68(param_1,2,0x10,0);
  }
  else {
    iVar2 = func_0x80036c68(param_1,2,0x10,0);
    iVar3 = func_0x80036c68(param_1,2,0x10,0);
    iVar2 = iVar2 + iVar3;
  }
  *(undefined1 *)(param_1 + 0x2c1) = 1;
  *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + (iVar2 != 0);
LAB_801629a4:
  if (0 < *(short *)(param_1 + 0x2b8)) {
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 6;
    *(short *)(param_1 + 0x2b8) = *(short *)(param_1 + 0x2b8) + -6;
  }
  if (0 < *(short *)(param_1 + 0x2ba)) {
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + -6;
    *(short *)(param_1 + 0x2ba) = *(short *)(param_1 + 0x2ba) + -6;
  }
  return;
}
