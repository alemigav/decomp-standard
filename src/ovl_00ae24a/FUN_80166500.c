/* FUN_80166500
 * image   ovl_00ae24a (ovl), base 0x80161cf0
 * address 0x80166500  body 0x80166500..0x8016676b  size 620 B
 * body sha256 9b5a4951ad4228407e5303c956a2764ad436955c52eea627f189d40a88c4b9c8
 * provider record sha256 5f66b0aaf23cfabedffc86d286cf1859ea6e0ac15eee6f0bccc0b3e13d1b43af
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80166500(int param_1,int param_2)

{
  ushort uVar4;
  short sVar5;
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar6;
  int iVar7;
  short local_20;
  short local_1e;
  short local_1c;
  
  switch(*(undefined1 *)(param_1 + 0x2b5)) {
  case 0:
    *(undefined1 *)(param_1 + 0x2b5) = 1;
    *(undefined2 *)(param_1 + 0x2b8) = 0;
    *(undefined2 *)(param_1 + 0x2ba) = 0;
    *(undefined1 *)(param_1 + 0x2b7) = 0;
  case 1:
    sVar5 = *(short *)(*(int *)(param_2 + 0x120) + 0x18);
    if (sVar5 != 0) {
      *(short *)(*(int *)(param_2 + 0x120) + 0x18) = sVar5 >> 1;
    }
    *(short *)(*(int *)(param_2 + 0x120) + 0xc) =
         *(short *)(*(int *)(param_2 + 0x120) + 0xc) - *(short *)(param_1 + 0x2b8);
    if (*(short *)(*(int *)(param_2 + 0x120) + 0xc) < -0xfd0) {
      *(undefined1 *)(param_1 + 0x2b5) = 2;
    }
    *(short *)(param_1 + 0x2b8) = *(short *)(param_1 + 0x2b8) + 0x20;
    break;
  case 2:
    uVar4 = func_0x80033604();
    *(ushort *)(*(int *)(param_2 + 0x120) + 0xc) =
         *(short *)(*(int *)(param_2 + 0x120) + 0xc) + 0x20 +
         (uVar4 & 0xff) * 4 * ((*(ushort *)(param_1 + 0x2ba) & 1) * -2 + 1);
    if (8000 < *(short *)(*(int *)(param_2 + 0x120) + 0xc)) {
      *(undefined2 *)(*(int *)(param_2 + 0x120) + 0xc) = 8000;
    }
    if (*(short *)(*(int *)(param_2 + 0x120) + 0xc) < -5000) {
      *(undefined2 *)(*(int *)(param_2 + 0x120) + 0xc) = 0xec78;
    }
    sVar5 = *(short *)(param_1 + 0x2ba) + 1;
    *(short *)(param_1 + 0x2ba) = sVar5;
    if (300 < sVar5) {
      *(undefined1 *)(param_1 + 0x2b5) = 3;
    }
    iVar7 = 0x1fa0;
    if (0x96 < *(short *)(param_1 + 0x2ba)) {
      iVar7 = 0x17d0;
    }
    if (0xfa < *(short *)(param_1 + 0x2ba)) {
      iVar7 = 0xfd0;
    }
    if ((*(ushort *)(param_1 + 0x2ba) & 1) != 0) {
      iVar6 = *(int *)(param_1 + 0x234);
      uVar4 = func_0x80033604();
      local_20 = 0x80 - (uVar4 & 0xff);
      uVar4 = func_0x80033604();
      local_1e = 0x80 - (uVar4 & 0xff);
      uVar4 = func_0x80033604();
      local_1c = 0x80 - (uVar4 & 0xff);
      uVar1 = func_0x80033604();
      uVar2 = func_0x80033604();
      uVar3 = func_0x80033604();
      func_0x80037780(((uVar1 & 1) + (uVar2 & 0x10)) * 0x10000 | iVar7 + (uVar3 & 0xff) * 4,
                      (int)*(short *)(param_1 + 0x66),iVar6 + 0x618,&local_20);
    }
    break;
  case 3:
    *(short *)(*(int *)(param_2 + 0x120) + 0xc) = *(short *)(*(int *)(param_2 + 0x120) + 0xc) + 0x40
    ;
    if (12000 < *(short *)(*(int *)(param_2 + 0x120) + 0xc)) {
      *(undefined1 *)(param_1 + 0x2b5) = 4;
    }
    break;
  case 4:
    *(short *)(*(int *)(param_2 + 0x120) + 0xc) =
         *(short *)(*(int *)(param_2 + 0x120) + 0xc) + -0x80;
    if (*(short *)(*(int *)(param_2 + 0x120) + 0xc) < 0) {
      *(undefined1 *)(param_1 + 0x2b5) = 5;
    }
  }
  return;
}
