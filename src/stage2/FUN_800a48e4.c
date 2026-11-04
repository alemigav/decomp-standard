/* FUN_800a48e4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a48e4  body 0x800a48e4..0x800a4dc3  size 1248 B
 * body sha256 02a477ab98314eb11bdd38284ff87d5859f15ba20d5d83ee04b7544b0196f6c4
 * provider record sha256 4ee01d5fab0e78bcb092aebf50b3a1f3612570f66edc91a8f48d6c786c9a546d
 * callees 14 direct (14 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800a48e4(void)

{
  int *piVar1;
  undefined4 uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  short sVar6;
  short sVar7;
  ushort uVar8;
  
  if (_DAT_80143fd8 != (code *)0x0) {
    (*_DAT_80143fd8)();
  }
  FUN_800a5700();
  uVar2 = func_0x800072e0();
  if (DAT_80143f00 == 0) {
    uVar3 = _DAT_80143f0a;
  }
  else {
    uVar3 = (ushort)DAT_80143f00;
  }
  uVar3 = uVar3 - 1;
  func_0x80007300(uVar2);
  if (DAT_80136310 != '\0') {
    FUN_800aa1ac();
  }
  if (_DAT_80143fa0 == 0xffff) {
    _DAT_80143fa0 = uVar3;
  }
  else {
    if (DAT_80143f4c != '\0') {
      osRecvMesg(0x80143f30,0,1);
      DAT_80143f4c = '\0';
      func_0x80011390();
    }
    _DAT_80143fcc = 0;
    _DAT_80143fdc = _DAT_80143fec & 0xfffffff0;
    _DAT_80143fd0 = _DAT_80143fec;
    piVar1 = _DAT_80143f84;
    if (_DAT_80143fd4 != (code *)0x0) {
      (*_DAT_80143fd4)();
      piVar1 = _DAT_80143f84;
    }
    for (; piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
      if (*(short *)(piVar1 + 4) != 0) {
        *(short *)(piVar1 + 4) = *(short *)(piVar1 + 4) + -1;
      }
    }
    _DAT_80143f54 = (undefined2 *)(&DAT_80143f60 + (uint)DAT_80143f16 * 2);
    _DAT_80143f50 = *(undefined2 **)(&DAT_80143f58 + (uint)DAT_80143f16 * 4);
    _DAT_80143fe0 = _DAT_80143f50 + 8;
    _DAT_80143fe4 = (uint)_DAT_80143fe0 & 0xfffffff0;
    *_DAT_80143f54 = 0;
    *_DAT_80143f50 = 0;
    if (_DAT_80143fa0 != uVar3) {
      sVar6 = 0;
      FUN_800a485c();
      uVar8 = 0;
      uVar5 = _DAT_80143fa0;
      if (_DAT_80143fa0 < uVar3) {
        do {
          if (_DAT_80143f4e <= uVar8) break;
          uVar4 = uVar5 + 1;
          if ((DAT_80136310 != '\0') && (_DAT_80143f18 = _DAT_80143f18 + -1, _DAT_80143f18 == 0)) {
            _DAT_80143f18 = _DAT_80143f1c;
            FUN_800a1be8();
            FUN_800a8470();
          }
          uVar8 = uVar8 + 1;
          FUN_800a4560(*(undefined4 *)(&DAT_80143ea0 + (uint)uVar5 * 4),sVar6);
          uVar5 = uVar4;
          sVar6 = sVar6 + 0xc0;
        } while (uVar4 < uVar3);
      }
      else {
        sVar7 = sVar6;
        if (_DAT_80143fa0 < _DAT_80143f0a) {
          do {
            sVar7 = sVar6;
            if (_DAT_80143f4e <= uVar8) break;
            uVar4 = uVar5 + 1;
            if ((DAT_80136310 != '\0') && (_DAT_80143f18 = _DAT_80143f18 + -1, _DAT_80143f18 == 0))
            {
              _DAT_80143f18 = _DAT_80143f1c;
              FUN_800a1be8();
              FUN_800a8470();
            }
            sVar7 = sVar6 + 0xc0;
            uVar8 = uVar8 + 1;
            FUN_800a4560(*(undefined4 *)(&DAT_80143ea0 + (uint)uVar5 * 4),sVar6);
            sVar6 = sVar7;
            uVar5 = uVar4;
          } while (uVar4 < _DAT_80143f0a);
        }
        uVar4 = 0;
        uVar5 = 0;
        if (uVar3 != 0) {
          do {
            uVar5 = uVar4;
            if (_DAT_80143f4e <= uVar8) break;
            uVar5 = uVar4 + 1;
            if ((DAT_80136310 != '\0') && (_DAT_80143f18 = _DAT_80143f18 + -1, _DAT_80143f18 == 0))
            {
              _DAT_80143f18 = _DAT_80143f1c;
              FUN_800a1be8();
              FUN_800a8470();
            }
            uVar8 = uVar8 + 1;
            FUN_800a4560(*(undefined4 *)(&DAT_80143ea0 + (uint)uVar4 * 4),sVar7);
            uVar4 = uVar5;
            sVar7 = sVar7 + 0xc0;
          } while (uVar5 < uVar3);
        }
      }
      if (_DAT_80143fcc != 0) {
        DAT_80143f4c = '\x01';
        (*_DAT_80144000)(_DAT_80143fec,_DAT_80143fcc,0x80143f30);
      }
      _DAT_80143fa2 = _DAT_80143fa2 - uVar8;
      _DAT_80143fa0 = uVar5;
    }
    FUN_800a9578();
    _DAT_80143f54 = (undefined2 *)(&DAT_80143f60 + (DAT_80143f16 ^ 1) * 2);
    _DAT_80143f50 = *(undefined2 **)(&DAT_80143f58 + (DAT_80143f16 ^ 1) * 4);
    if (DAT_80143f4d != '\0') {
      (*_DAT_80143ff4)();
      func_0x80011390();
      DAT_80143f4d = '\0';
    }
    FUN_800a2e40();
    DAT_80143f16 = DAT_80143f16 ^ 1;
    if (DAT_80136310 != '\0') {
      FUN_800a9110();
    }
  }
  FUN_800a5728();
  return;
}
