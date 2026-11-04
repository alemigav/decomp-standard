/* FUN_8004f9f0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004f9f0  body 0x8004f9f0..0x8004fc33  size 580 B
 * body sha256 286b8be7b07253a5598bac7a00936c9a5e4a72c8a6b143092d70846134f76a25
 * provider record sha256 170cc4e83f34817408e62644ad4a2eb547e6bea20df53e02c64f3f2fa7bcff3b
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8004f9f0(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined1 *puVar6;
  short *psVar7;
  int *piVar8;
  
  iVar1 = param_1 * 0x368;
  (&DAT_800e19b0)[param_1 * 0xda] = *(undefined4 *)(param_2 + 0x40);
  *(undefined4 *)(&DAT_800e19b4 + iVar1) = *(undefined4 *)(param_2 + 0x44);
  (&DAT_800e19b8)[param_1 * 0xda] = *(undefined4 *)(param_2 + 0x48);
  (&DAT_800e19bc)[param_1 * 0xda] = *(undefined4 *)(param_2 + 0x4c);
  *(undefined2 *)(&DAT_800e19cc + iVar1) = *(undefined2 *)(param_2 + 0x5c);
  *(undefined2 *)(&DAT_800e19ce + iVar1) = *(undefined2 *)(param_2 + 0x5e);
  *(undefined4 *)(&DAT_800e19d4 + iVar1) = *(undefined4 *)(param_2 + 100);
  *(undefined4 *)(&DAT_800e19d0 + iVar1) = *(undefined4 *)(param_2 + 0x60);
  *(undefined4 *)(&DAT_800e1b88 + iVar1) = *(undefined4 *)(param_2 + 0x40);
  *(undefined4 *)(&DAT_800e1b8c + iVar1) = *(undefined4 *)(param_2 + 0x44);
  *(undefined4 *)(&DAT_800e1b90 + iVar1) = *(undefined4 *)(param_2 + 0x48);
  *(undefined4 *)(&DAT_800e1b94 + iVar1) = *(undefined4 *)(param_2 + 0x4c);
  *(undefined2 *)(&DAT_800e1ba4 + iVar1) = *(undefined2 *)(param_2 + 0x5c);
  *(undefined2 *)(&DAT_800e1ba6 + iVar1) = *(undefined2 *)(param_2 + 0x5e);
  *(undefined4 *)(&DAT_800e1bac + iVar1) = *(undefined4 *)(param_2 + 100);
  iVar5 = (&DAT_800e19bc)[param_1 * 0xda];
  *(undefined4 *)(&DAT_800e1ba8 + iVar1) = *(undefined4 *)(param_2 + 0x60);
  if (iVar5 == 0) {
    *(undefined4 *)(&DAT_800e1ba8 + iVar1) = 0;
  }
  else {
    *(undefined4 *)(&DAT_800e1ba8 + iVar1) = *(undefined4 *)(iVar5 + 8);
    DAT_800df934 = FUN_80031b80(&DAT_800e1970 + iVar1,DAT_800df934);
  }
  *(undefined4 *)(&DAT_800e1b88 + iVar1) = *(undefined4 *)(param_2 + 0x40);
  uVar2 = *(undefined4 *)(param_2 + 0x44);
  psVar7 = &DAT_8010bb00;
  *(undefined4 *)(&DAT_800e18fc + iVar1) = 0;
  *(undefined4 *)(&DAT_800e1964 + iVar1) = 0x808080;
  *(undefined4 *)(&DAT_800e19d4 + iVar1) = 0xffffffff;
  *(undefined4 *)(&DAT_800e1b8c + iVar1) = uVar2;
  uVar4 = (uint)DAT_800e8ca8;
  uVar3 = (uint)DAT_800e8caa;
  (&DAT_800e1c5c)[param_1 * 0xda] = 0;
  while (((int)*psVar7 != (int)(((uVar4 + 1) * 0x1000 + uVar3 * 0x10) * 0x10000) >> 0x10 ||
         (param_1 != psVar7[1]))) {
    psVar7 = psVar7 + 4;
    if (*psVar7 == -1) {
LAB_8004fb9c:
      if ((&DAT_800e1900)[iVar1] == '\x01') {
        piVar8 = *(int **)(*(int *)((&DAT_800e19bc)[param_1 * 0xda] + 8) + 8);
        *(int **)(*(int *)((&DAT_800e19bc)[param_1 * 0xda] + 8) + 4) = piVar8;
        if ((&DAT_800e19b8)[param_1 * 0xda] != 0) {
          func_0x8000de9c((&DAT_800e19b8)[param_1 * 0xda],*piVar8,
                          (int)*(short *)((int)piVar8 + 0xe) << 4);
        }
        iVar1 = *(short *)((int)piVar8 + 0xe) + -1;
        if (iVar1 != -1) {
          puVar6 = (undefined1 *)(*piVar8 + 0xf);
          do {
            puVar6[-3] = 0xff;
            puVar6[-2] = 0xff;
            puVar6[-1] = 0xff;
            *puVar6 = 0xff;
            iVar1 = iVar1 + -1;
            puVar6 = puVar6 + 0x10;
          } while (iVar1 != -1);
        }
      }
      return;
    }
  }
  (&DAT_800e1c5c)[param_1 * 0xda] = psVar7 + 2;
  (&DAT_800e1900)[iVar1] = 1;
  goto LAB_8004fb9c;
}
