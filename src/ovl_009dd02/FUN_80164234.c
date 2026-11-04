/* FUN_80164234
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80164234  body 0x80164234..0x80164327  size 244 B
 * body sha256 6062eda21eaa17459192e540e1f3815b9287157dd20feddde4bf049a38f806b0
 * provider record sha256 1b9f702ccd1613d2c6d339e24be1cd8b58cd17e5712b792ae1c876313b53cd16
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80164234(int param_1)

{
  uint uVar1;
  undefined2 uVar2;
  undefined1 *puVar3;
  
  if (*(char *)(param_1 + 0x2b4) == '\0') {
    puVar3 = &DAT_800e1130;
  }
  else {
    puVar3 = _DAT_800e13ec;
  }
  *(undefined1 *)(param_1 + 0x25c) = 1;
  *(undefined1 *)(param_1 + 0x25d) = 0;
  if (*(short *)(param_1 + 0x1aa) == 0x6005) {
    if (*(short *)(param_1 + 0x270) != 0) {
      *(undefined2 *)(param_1 + 6) = 0x100;
    }
  }
  else {
    if (*(char *)(param_1 + 0x2b4) == '\0') {
      uVar1 = *(uint *)(param_1 + 0x28c);
    }
    else {
      uVar1 = *(uint *)(param_1 + 0x290) & 0x3fffffff;
    }
    if ((uVar1 < 4000) && (-1 < *(short *)(puVar3 + 0x1f2))) {
      *(undefined2 *)(param_1 + 6) = 0x100;
    }
  }
  uVar2 = func_0x80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                          (int)*(short *)(puVar3 + 0x2a),(int)*(short *)(puVar3 + 0x32));
  *(undefined2 *)(param_1 + 0x66) = uVar2;
  *(undefined1 *)(param_1 + 0x2c1) = 8;
  *(undefined1 *)(param_1 + 0x2c3) = 3;
  return;
}
