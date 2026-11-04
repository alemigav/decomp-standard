/* FUN_80162de0
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80162de0  body 0x80162de0..0x8016304b  size 620 B
 * body sha256 c9fb88b4daf9c0dc2ce0ba0b2e782c1dd6bc366ac73927dfa6df8e41d2410acb
 * provider record sha256 b3bbf3bf7fe5af4be35eca208e31ce763c992db3ddfb601eabd8850303173dac
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162de0(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined2 uVar1;
  short sVar2;
  short sVar4;
  ushort uVar5;
  undefined1 uVar6;
  int iVar3;
  undefined1 *puVar7;
  
  if (*(char *)(param_1 + 0x2b4) == '\0') {
    puVar7 = &DAT_800e1130;
  }
  else {
    puVar7 = _DAT_800e13ec;
  }
  sVar4 = func_0x80032e74(param_1,*(undefined4 *)(puVar7 + 0x28),*(undefined4 *)(puVar7 + 0x30),0x30
                         );
  if (*(short *)(puVar7 + 0x1f2) < 0) {
    sVar4 = -sVar4;
  }
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    *(undefined1 *)(param_1 + 6) = 1;
    *(char *)(param_1 + 0x2bf) = (char)sVar4;
    *(undefined2 *)(param_1 + 0x1f6) = 0x3c;
    *(undefined2 *)(param_1 + 100) = 0;
switchD_80162e80_caseD_1:
    *(undefined1 *)(param_1 + 6) = 2;
    uVar5 = func_0x80033604();
    *(ushort *)(param_1 + 500) = (uVar5 & 0xf) + 0xf;
    *(undefined4 *)(param_1 + 0x1e8) = 0x3000f00;
switchD_80162e80_caseD_2:
    *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + (short)*(char *)(param_1 + 0x2bf);
    sVar2 = *(short *)(param_1 + 500);
    uVar1 = *(undefined2 *)(&LAB_801666e4 + (*(ushort *)(param_1 + 500) & 7) * 2);
    *(short *)(param_1 + 500) = sVar2 + -1;
    *(undefined2 *)(param_1 + 100) = uVar1;
    if (sVar2 == 1) {
      uVar6 = 3;
LAB_80162f54:
      *(undefined1 *)(param_1 + 6) = uVar6;
    }
switchD_80162e80_default:
    sVar2 = *(short *)(param_1 + 0x1f6);
    *(short *)(param_1 + 0x1f6) = sVar2 + -1;
    if ((sVar2 == 1) || (sVar4 == 0)) {
      if (((*(byte *)(param_1 + 0x2bd) & 1) == 0) || (uVar6 = 0xb, _DAT_800e1322 < 0)) {
        uVar6 = 9;
      }
      *(undefined1 *)(param_1 + 5) = uVar6;
      *(undefined2 *)(param_1 + 6) = 0;
    }
    if ((((*(byte *)(param_1 + 0x2bd) & 1) == 0) && (*(char *)(param_1 + 0x2c8) == '\0')) &&
       (iVar3 = FUN_80165fb4(param_1,0,0x73a,0x180), iVar3 != 0)) {
      *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
      puVar7[0x26f] = puVar7[0x26f] | 0x80;
      *(undefined1 *)(param_1 + 5) = 3;
      *(undefined2 *)(param_1 + 6) = 0;
    }
    FUN_801623ac(param_1);
    func_0x80089d54(param_1,param_2,param_3,0x100);
    func_0x80033648(param_1);
    return;
  case 1:
    goto switchD_80162e80_caseD_1;
  case 2:
    goto switchD_80162e80_caseD_2;
  case 3:
    *(undefined1 *)(param_1 + 6) = 4;
    *(undefined4 *)(param_1 + 0x1e8) = 0xf00;
    uVar5 = func_0x80033604();
    *(ushort *)(param_1 + 500) = (uVar5 & 0xf) + 0xf;
    *(undefined2 *)(param_1 + 100) = 0;
  case 4:
    sVar2 = *(short *)(param_1 + 500);
    *(short *)(param_1 + 500) = sVar2 + -1;
    uVar6 = 1;
    if (sVar2 != 1) goto switchD_80162e80_default;
    goto LAB_80162f54;
  default:
    goto switchD_80162e80_default;
  }
}
