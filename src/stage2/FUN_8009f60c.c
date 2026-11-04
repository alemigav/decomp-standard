/* FUN_8009f60c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009f60c  body 0x8009f60c..0x8009f64f  size 68 B
 * body sha256 5643f87448f38addda0ee2afaefc56e49a3d160b6ae92413483cfb2d4228dade
 * provider record sha256 7988090e52f31a519d6f10f6618de2bf1002f298fbc75cf41184bc8f8f01e7a1
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8009f60c(void)

{
  int iVar1;
  
  DAT_801344c4 = DAT_801344c8;
  switch(DAT_801344c8) {
  case 0:
    DAT_801344d4 = 0;
    DAT_801344d8 = 0;
    break;
  case 1:
    do {
    } while (DAT_801344f4 != 0);
    FUN_8009eee0(*(undefined4 *)((DAT_80184b38 ^ 1) * 4 + -0x7fe7b4d0),
                 *(undefined4 *)((uint)DAT_80184b38 * 4 + -0x7fe7b4d0));
    DAT_801344cc = 0;
    DAT_801344c8 = 2;
    DAT_801344d4 = DAT_801344d4 + 1;
    break;
  case 2:
    DAT_801344cc = DAT_801344cc + 1;
    DAT_80184b38 = DAT_80184b38 ^ 1;
    func_0x8000ec60(*(undefined4 *)((uint)DAT_80184b38 * 4 + -0x7fe7b4d0));
    DAT_801344c8 = 3;
    break;
  case 3:
    DAT_801344cc = 0;
    if (DAT_801344d8 == 0) {
      DAT_801344c8 = 4;
    }
    else {
      iVar1 = func_0x80180c10();
      if (iVar1 == 0) {
        if ((DAT_801344d8 & 1) == 0) {
          DAT_801344d4 = DAT_801344d4 + 1;
        }
        DAT_801344d8 = DAT_801344d8 - 1;
      }
      else {
        _DAT_8018547c = 1;
        DAT_801344d8 = 0;
      }
    }
    break;
  case 4:
    DAT_801344cc = DAT_801344cc + 1;
    if (DAT_801344d0 != 0) {
      DAT_801344d0 = 0;
      DAT_801344fc = DAT_80184b38 ^ 1;
      FUN_8009ec1c(0x80184b3c,*(undefined4 *)((DAT_80184b38 ^ 1) * 4 + -0x7fe7b4d0));
      DAT_801344d4 = DAT_801344d4 + 1;
      DAT_801344c8 = 1;
    }
  }
  DAT_801344f8 = DAT_801344f8 + 1;
  return;
}
