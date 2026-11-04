/* FUN_801666f8
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x801666f8  body 0x801666f8..0x801668fb  size 516 B
 * body sha256 d1afef7eab3a3f0b69fe643f4fcbf26df6ccaa367e07e127b21a21f4f48fd7cd
 * provider record sha256 87f7155e34b894b58432ec0b60410a8404d242593df4e171bb2f3a91d622dc18
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char FUN_801666f8(uint *param_1,int param_2)

{
  int iVar1;
  char cVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  uint *puVar5;
  
  if (param_2 == 0) {
    puVar5 = (uint *)0x800e1130;
  }
  else {
    puVar5 = _DAT_800e13ec;
  }
  uVar4 = 700;
  if (0x14 < *(short *)((int)puVar5 + 0x1f2)) {
    uVar4 = 1000;
  }
  cVar2 = *(char *)((int)param_1 + 0x2ba);
  if (cVar2 == '\0') {
    if (((((*(byte *)((int)puVar5 + 0x26f) & 0x80) == 0) &&
         (iVar1 = func_0x80033024(puVar5 + 10,param_1[0x8d] + 0x62c,uVar4), iVar1 != 0)) &&
        (*(short *)((int)param_1 + 0x25e) + -0x708 < (int)param_1[0xb])) &&
       (*(char *)((int)puVar5 + 0x1a2) == *(char *)((int)param_1 + 0x1a2))) {
      *(undefined2 *)((int)param_1 + 0x2b6) = 0;
      if (param_2 == 0) {
        iVar1 = func_0x80059e00(0x14,0);
      }
      else {
        iVar1 = func_0x80080e00(param_1,0x14,0);
      }
      if (((iVar1 == 2) && (cVar2 = func_0x80033144(param_1,puVar5), cVar2 == '\0')) &&
         ((*(char *)((int)param_1 + 0x2c3) == '\0' && (*(char *)(puVar5 + 2) != '\x0f')))) {
        *(undefined1 *)((int)param_1 + 0x2ba) = 2;
        *(undefined2 *)(param_1 + 0x78) = 0;
        *(undefined1 *)((int)puVar5 + 0x26f) = 0xff;
        *puVar5 = *puVar5 | 10;
        *(short *)((int)puVar5 + 0x66) = *(short *)((int)param_1 + 0x66) + 0x800;
        _DAT_800e10ec = _DAT_800e10ec & 0xfbffffff;
        *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) | 0x80;
      }
      else {
        *(undefined2 *)((int)param_1 + 6) = 0x300;
        *(undefined1 *)((int)param_1 + 0x2ba) = 1;
        if (*(short *)((int)puVar5 + 0x1f2) < 0) {
          FUN_80166b1c(param_2);
          *param_1 = *param_1 | 2;
        }
        else {
          uVar3 = func_0x80033144(param_1,puVar5);
          FUN_80166ac8(param_2,uVar3);
        }
      }
    }
    cVar2 = *(char *)((int)param_1 + 0x2ba);
  }
  return cVar2;
}
