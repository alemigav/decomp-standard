/* FUN_80162d8c
 * image   ovl_009d3ba (ovl), base 0x80161cf0
 * address 0x80162d8c  body 0x80162d8c..0x80162e37  size 172 B
 * body sha256 895dd6a4720866addf2a078b08260932404c6a3588f4261102e36b6f17ec50e2
 * provider record sha256 0a60c71c328a1749b801d9f3fc6dd1d1a2aa2feac91337755748322b03996632
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162d8c(uint *param_1,uint param_2,char param_3)

{
  uint uVar1;
  byte bVar2;
  uint *puVar3;
  
  bVar2 = 7;
  uVar1 = 7;
  do {
    puVar3 = (uint *)(param_1[0x8d] +
                     (uint)(byte)(&UNK_8016301f)[uVar1 + (param_2 & 0xff) * 7] * 0x178);
    if (param_3 == '\0') {
      uVar1 = *puVar3 & 0xfffffffe;
    }
    else {
      uVar1 = *puVar3 | 1;
    }
    *puVar3 = uVar1;
    bVar2 = bVar2 - 1;
    uVar1 = (uint)bVar2;
  } while (bVar2 != 0);
  if (param_3 == '\0') {
    *param_1 = *param_1 | 2;
    return;
  }
  *param_1 = *param_1 & 0xfffffffd;
  return;
}
