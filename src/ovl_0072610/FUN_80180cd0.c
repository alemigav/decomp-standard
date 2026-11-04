/* FUN_80180cd0
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x80180cd0  body 0x80180cd0..0x80181017  size 840 B
 * body sha256 e772221c225b22151b2eb0c4b6d55ec30a1e867b809cb72b8627116282c2e414
 * provider record sha256 49751e81daa717ef50b539b31b4b416cd524020e831b73eb83f1acffed4b6387
 * callees 9 direct (9 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80180cd0(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  DAT_8018548c = func_0x80025b0c();
  DAT_80185494 = 0;
  DAT_80185490 = 0;
  _DAT_80012820 = _DAT_8010b6f8;
  DAT_80185470 = 0;
  DAT_80185474 = 0;
  DAT_80185478 = 0;
  DAT_80185480 = 0xffffffff;
  DAT_80185484 = 0xffffffff;
  DAT_80185488 = 0xffffffff;
  DAT_80184b38 = _DAT_800c56f4 != 0;
  FUN_80180be4();
  func_0x8009f5b0();
  _DAT_800e10ec = _DAT_800e10ec | 0x8000;
  do {
    bVar1 = false;
    if ((*(short *)((_DAT_801344b0 * 0x89 + DAT_80185470) * 2 + -0x7fecbae4) == -1) ||
       (iVar3 = func_0x80004c9c((int)*(short *)((_DAT_801344b0 * 0x89 + DAT_80185470) * 2 +
                                               -0x7fecbae4)), iVar3 == 0)) {
      bVar1 = true;
    }
    iVar2 = DAT_80185470;
    iVar3 = _DAT_801344b0;
    if (bVar1) {
      *(undefined2 *)((_DAT_801344b0 * 0x89 + DAT_80185470) * 2 + -0x7fecbae4) = 0x9af;
      *(undefined1 *)(iVar2 + iVar3 * 0x112 + -0x7fecba6c) = 0x10;
    }
    FUN_8017b60c((int)*(short *)((_DAT_801344b0 * 0x89 + DAT_80185470) * 2 + -0x7fecbae4));
    uVar4 = 1;
    if (DAT_80185470 != 0) {
      bVar1 = false;
      if ((*(short *)((_DAT_801344b0 * 0x89 + DAT_80185470 + 1) * 2 + -0x7fecbae4) == -1) ||
         (DAT_80185470 == 0x27)) {
        bVar1 = true;
      }
      uVar4 = 2;
      if (bVar1) {
        uVar4 = 4;
      }
    }
    FUN_8018152c(uVar4,*(undefined1 *)(DAT_80185470 + _DAT_801344b0 * 0x112 + -0x7fecba6c),
                 *(undefined1 *)(DAT_80185470 + _DAT_801344b0 * 0x112 + -0x7fecba94));
    DAT_80185470 = DAT_80185470 + 1;
    bVar1 = false;
    if (DAT_8018547c == 0) {
      bVar1 = *(short *)((_DAT_801344b0 * 0x89 + DAT_80185470) * 2 + -0x7fecbae4) != -1;
    }
  } while (bVar1);
  FUN_80180958();
  _DAT_800e9254 = (&DAT_80184b30)[DAT_80184b38];
  func_0x8009f47c();
  func_0x80025b1c(DAT_8018548c);
  _DAT_801344c0 = 4;
  return;
}
