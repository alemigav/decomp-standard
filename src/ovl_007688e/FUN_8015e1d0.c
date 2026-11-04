/* FUN_8015e1d0
 * image   ovl_007688e (ovl), base 0x8015b030
 * address 0x8015e1d0  body 0x8015e1d0..0x8015e383  size 436 B
 * body sha256 3ca5dd6f3acf7118cedd8001333b14c3415e97033132996fb46de2f16ca6d8e7
 * provider record sha256 19674eb287d66162d3129f60cf5f2731e70d62ff5946bc8697912d2d72aa972e
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8015e1d0(void)

{
  int iVar1;
  undefined2 uVar2;
  undefined2 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  
  uVar8 = 0;
  DAT_801614d4 = &DAT_801608c8;
  puVar7 = (undefined4 *)&DAT_80160c38;
  do {
    uVar5 = 0;
    iVar6 = 0;
    puVar4 = puVar7;
    do {
      *puVar4 = 0x808080;
      *(undefined1 *)((int)puVar4 + 3) = 0;
      puVar3 = DAT_801614d4;
      puVar4[3] = &DAT_8016149c;
      puVar3 = (undefined2 *)(iVar6 + (int)puVar3);
      *(undefined2 *)(puVar4 + 1) = *puVar3;
      *(undefined2 *)((int)puVar4 + 6) = puVar3[1];
      *(undefined2 *)(puVar4 + 4) = puVar3[2];
      *(undefined2 *)((int)puVar4 + 0x12) = puVar3[3];
      *(undefined1 *)(puVar4 + 2) = *(undefined1 *)(puVar3 + 4);
      *(undefined1 *)((int)puVar4 + 9) = *(undefined1 *)((int)DAT_801614d4 + iVar6 + 9);
      if (uVar5 < 0x2c) {
        *(undefined2 *)((int)puVar4 + 10) = 0;
      }
      else {
        if (uVar5 == 0x30) {
          uVar2 = 0x140;
        }
        else {
          uVar2 = 0x100;
          if (0x30 < uVar5) {
            puVar4[3] = &DAT_80161480;
            *(undefined2 *)((int)puVar4 + 10) = 0;
            goto LAB_8015e2c4;
          }
        }
        *(undefined2 *)((int)puVar4 + 10) = uVar2;
      }
LAB_8015e2c4:
      uVar5 = uVar5 + 1;
      iVar1 = iVar6 + 10;
      iVar6 = iVar6 + 0xc;
      func_0x80047b04(puVar4,*(undefined1 *)((int)DAT_801614d4 + iVar1));
      puVar4 = puVar4 + 10;
    } while (uVar5 < 0x34);
    uVar8 = uVar8 + 1;
    puVar7 = puVar7 + 5;
    if (1 < uVar8) {
      if ((_DAT_800e10ec & 1) != 0) {
        DAT_801613bc = DAT_801613bc + 0x10;
        DAT_801613d0 = DAT_801613d0 + 0x10;
        DAT_801613be = DAT_801613be + -4;
        DAT_801613d2 = DAT_801613d2 + -4;
      }
      return;
    }
  } while( true );
}
