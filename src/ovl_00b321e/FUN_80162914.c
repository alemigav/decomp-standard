/* FUN_80162914
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80162914  body 0x80162914..0x80162a03  size 240 B
 * body sha256 a1a798f8e37713f3d360d63d68333a7e80cdea047007ca39c4f283d0130b311a
 * provider record sha256 a8bd20512890608537bc4136e6e6633731d3c09c32584afa1f78f97b3a900fc6
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162914(uint *param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  
  *(undefined2 *)((int)param_1 + 6) = 0x100;
  *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) | 0x80;
  *param_1 = *param_1 | 2;
  _DAT_800e1354 = param_1[0x89];
  _DAT_800e1134 = 0x5000000;
  _DAT_800e1358 = param_1[0x8a];
  DAT_800e139f = DAT_800e139f | 0x80;
  _DAT_800e1380 = param_1;
  param_1[0x7a] = 0x9000f00;
  if (*(char *)(param_1 + 0xad) == '\0') {
    uVar3 = param_1[0xa3];
  }
  else {
    uVar3 = param_1[0xa4] & 0x3fffffff;
  }
  cVar1 = func_0x80033144(param_1,&DAT_800e1130);
  iVar2 = 1000;
  if (cVar1 != '\0') {
    iVar2 = 500;
  }
  *(undefined2 *)(param_1 + 0x19) = 0;
  *(undefined1 *)((int)param_1 + 0x2de) = 0;
  *(short *)(param_1 + 0x78) = (short)((int)(uVar3 - iVar2) / 0x1a);
  return;
}
