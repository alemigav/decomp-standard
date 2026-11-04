/* FUN_80163a10
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80163a10  body 0x80163a10..0x80163cdb  size 716 B
 * body sha256 9a5065ceaab5521cbc059068f81763d23f1852fac2813a8d521a19618360eb6a
 * provider record sha256 cbe5bc7163b7351c9242e0c684609e2dddd59e0b4fe24273426ca08c89a7b5bc
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80163a10(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  undefined2 uVar2;
  short sVar4;
  ushort uVar5;
  int iVar3;
  uint uVar6;
  
  if (*(char *)(param_1 + 0x2b4) == '\0') {
    uVar6 = *(uint *)(param_1 + 0x28c);
  }
  else {
    uVar6 = *(uint *)(param_1 + 0x290) & 0x3fffffff;
  }
  sVar4 = func_0x80032e74(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),
                          (int)*(char *)(param_1 + 0x2bf));
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        sVar4 = *(short *)(param_1 + 0x1f6);
        *(short *)(param_1 + 0x1f6) = sVar4 + -1;
        if ((sVar4 == 1) || ((int)uVar6 < 3000)) {
          *(undefined2 *)(param_1 + 6) = 0x100;
          uVar5 = func_0x80033604();
          *(ushort *)(param_1 + 0x1f6) = (uVar5 & 0x1f) + 0xf;
          *(undefined4 *)(param_1 + 0x1e8) = 0x3000f00;
        }
      }
      goto LAB_80163c20;
    }
    if (bVar1 != 0) goto LAB_80163c20;
    *(undefined4 *)(param_1 + 0x1e8) = 0x3000f00;
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 0x1e0) = 0x4b;
    *(short *)(param_1 + 500) = (short)((int)uVar6 / 0x4b);
    uVar5 = func_0x80033604();
    *(ushort *)(param_1 + 0x1f6) = (uVar5 & 0xf) + 0x1f;
    *(undefined1 *)(param_1 + 0x2bf) = 0x18;
    *(undefined2 *)(param_1 + 0x1e4) = 0;
    *(undefined2 *)(param_1 + 0x1e2) = 0;
    *(undefined2 *)(param_1 + 100) = 0;
  }
  func_0x800653d0(param_1,&DAT_800e1158,0,0);
  *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + sVar4;
  uVar2 = *(undefined2 *)(&LAB_801666e4 + (*(ushort *)(param_1 + 500) & 0xe));
  *(undefined2 *)(param_1 + 0x1e0) = 0x4b;
  *(undefined2 *)(param_1 + 100) = uVar2;
  if ((**(uint **)(param_1 + 0x214) & 0x10000) == 0) {
    *(undefined2 *)(param_1 + 0x1e0) = 0x25;
  }
  func_0x80032b5c(param_1,0);
  sVar4 = *(short *)(param_1 + 0x1f6);
  *(short *)(param_1 + 0x1f6) = sVar4 + -1;
  if (sVar4 == 1) {
    *(undefined2 *)(param_1 + 6) = 0x200;
    uVar5 = func_0x80033604();
    *(ushort *)(param_1 + 0x1f6) = (uVar5 & 0x1f) + 0xf;
    *(undefined2 *)(param_1 + 100) = 0;
    *(undefined4 *)(param_1 + 0x1e8) = 0xf00;
  }
  sVar4 = *(short *)(param_1 + 500);
  *(short *)(param_1 + 500) = sVar4 + -1;
  if (sVar4 == 1) {
    *(undefined1 *)(param_1 + 5) = 4;
    *(undefined2 *)(param_1 + 6) = 0;
  }
LAB_80163c20:
  if (((*(char *)(param_1 + 0x2c8) == '\0') && ((_DAT_800e1128 & 0x20) == 0)) &&
     (iVar3 = FUN_80165fb4(param_1,0,0x73a,0x180), iVar3 != 0)) {
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
    DAT_800e139f = DAT_800e139f | 0x80;
    *(undefined1 *)(param_1 + 5) = 3;
    *(undefined2 *)(param_1 + 6) = 0;
    _DAT_800e1128 = _DAT_800e1128 | 0x20;
  }
  func_0x80089d54(param_1,param_2,param_3,0x100);
  func_0x80033648(param_1);
  return;
}
