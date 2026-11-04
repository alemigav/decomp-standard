/* FUN_80163564
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80163564  body 0x80163564..0x80163607  size 164 B
 * body sha256 0820c7da193424c3f17411b4b439b343c992dcbb6382dd90dd0bf748be4a975b
 * provider record sha256 0c1622143a53778e00800717a25611752af3afeefb4c381a4d73a5afb0a8ec48
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163564(int param_1)

{
  uint uVar1;
  undefined1 uVar3;
  undefined2 uVar2;
  
  uVar1 = func_0x80033604();
  *(undefined *)(param_1 + 700) = (&DAT_80167298)[uVar1 & 7];
  uVar1 = func_0x80033604();
  *(char *)(param_1 + 0x2be) = (&DAT_80167298)[uVar1 & 7] + '\x1e';
  uVar3 = 0;
  if (*(char *)(param_1 + 0x206) != '\0') {
    uVar3 = 0xf;
  }
  *(undefined1 *)(param_1 + 0x2bd) = uVar3;
  uVar2 = 0xfce0;
  if (*(char *)(param_1 + 0x2cd) == '\0') {
    uVar2 = 800;
  }
  *(undefined2 *)(param_1 + 0x130) = uVar2;
  *(undefined1 *)(param_1 + 5) = 1;
  *(undefined2 *)(param_1 + 6) = 0;
  FUN_80166a04(param_1);
  return;
}
