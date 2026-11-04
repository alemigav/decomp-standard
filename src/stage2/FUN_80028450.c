/* FUN_80028450
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80028450  body 0x80028450..0x800284f3  size 164 B
 * body sha256 1c70e1f198548508889c9fca4b74c72a0a2eae3a08633580f5902f35ff8012b4
 * provider record sha256 c91ff3192757183c293a8d74f94aba5893c32d77b82cb1770c4a7ec7b617f1c9
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80028450(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = *param_1;
  FUN_8002fc00(param_1,0,400);
  param_1[3] = 1;
  *param_1 = uVar3;
  FUN_80030d68(param_1);
  iVar2 = 3;
  puVar1 = param_1 + 3;
  param_1[2] = 0;
  param_1[5] = 0;
  do {
    puVar1[0x1f] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + -1;
  } while (-1 < iVar2);
  iVar2 = 0;
  puVar1 = param_1;
  do {
    puVar1[0x23] = 0;
    puVar1[0x27] = 0;
    iVar2 = iVar2 + 1;
    puVar1 = puVar1 + 1;
  } while (iVar2 < 4);
  param_1[0x45] = 0;
  param_1[0x5d] = 0;
  FUN_8002d188(param_1);
  param_1[4] = 200;
  return;
}
