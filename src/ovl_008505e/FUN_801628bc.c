/* FUN_801628bc
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x801628bc  body 0x801628bc..0x80162a4b  size 400 B
 * body sha256 1ccdef263efff060dcc630e962bec0e52a55f83bf935c0fb36688e2106b9c196
 * provider record sha256 0df54806da2e9b06a48c053bf37cc45c9637fafbc70d629a7d370970464c6058
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801628bc(int param_1)

{
  char cVar1;
  int iVar2;
  undefined1 uVar3;
  short sVar4;
  int unaff_s3;
  
  FUN_80166528(param_1,0x28,0xf0);
  cVar1 = *(char *)(param_1 + 0x2b9);
  sVar4 = 0;
  if (cVar1 == '\0') {
    unaff_s3 = FUN_80166bd4(param_1);
    func_0x800653d0(param_1,unaff_s3 + 0x28,0,0);
    iVar2 = func_0x80032e74(param_1,(int)*(short *)(param_1 + 0x260),
                            (int)*(short *)(param_1 + 0x262),(int)*(short *)(param_1 + 0x2c0));
    if ((0xf < *(byte *)(param_1 + 0x2cc)) && (iVar2 == 0)) {
      iVar2 = (int)*(short *)(param_1 + 0x2c0);
    }
    *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + (short)iVar2;
    sVar4 = (short)iVar2;
  }
  else {
    *(char *)(param_1 + 0x2b9) = cVar1 + -1;
    if (cVar1 == '\x01') {
      *(undefined1 *)(param_1 + 0x2b9) = 0;
    }
    else {
      if ((*(uint *)(param_1 + 0x1ac) & 1) == 0) goto LAB_80162984;
      *(undefined1 *)(param_1 + 0x2b9) = 0;
    }
    *(undefined1 *)(param_1 + 700) = 0;
    sVar4 = 0;
  }
LAB_80162984:
  func_0x80032b5c(param_1,0);
  FUN_80166590(param_1,(int)sVar4);
  iVar2 = FUN_801665e8(param_1);
  if (iVar2 == 0) {
LAB_801629f4:
    if (0x1c2 < *(short *)(param_1 + 0x2b6)) {
      if (0x14 < *(short *)(unaff_s3 + 0x1f2)) {
        *(undefined2 *)(param_1 + 0x2b6) = 0;
      }
      *(undefined1 *)(param_1 + 0x2b8) = 1;
    }
    if (*(char *)(param_1 + 0x2b8) != '\0') {
      *(undefined1 *)(param_1 + 0x2b8) = 0;
      *(undefined2 *)(param_1 + 6) = 0x200;
    }
  }
  else {
    uVar3 = 3;
    if (iVar2 < 0) {
      *(short *)(param_1 + 0x2b6) = *(short *)(param_1 + 0x2b6) + 10;
      if (iVar2 != -2) {
        if (iVar2 == -4) {
          *(undefined1 *)(param_1 + 0x2b8) = 1;
        }
        goto LAB_801629f4;
      }
      uVar3 = 8;
    }
    *(undefined1 *)(param_1 + 5) = uVar3;
    *(undefined2 *)(param_1 + 6) = 0;
  }
  return;
}
