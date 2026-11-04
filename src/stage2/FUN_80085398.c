/* FUN_80085398
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80085398  body 0x80085398..0x8008548b  size 244 B
 * body sha256 2a593be3fdd81647dde6536a4a1e6b48f20ac11678e6435c2767d9a95d05d125
 * provider record sha256 219b9b6f2a013641e92e7a7cb1b937c7ba30ddef0d1ded4068896099a78c50b4
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80085398(uint param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  
  puVar4 = &DAT_8012487c;
  puVar7 = (uint *)0x0;
  uVar6 = 0xffffffff;
  uVar5 = 0;
  do {
    iVar1 = (int)uVar5 >> 5;
    uVar3 = 1 << (uVar5 & 0x1f);
    if (((((&DAT_8012486c)[iVar1] & uVar3) != 0) && (param_1 <= puVar4[1])) && (puVar4[1] < param_2)
       ) {
      puVar4[1] = uVar6;
      *puVar4 = *puVar4 | 0xff;
      (&DAT_8012486c)[iVar1] = (&DAT_8012486c)[iVar1] & ~uVar3;
      if (puVar7 == (uint *)0x0) {
        puVar7 = puVar4;
      }
      DAT_80124868 = DAT_80124868 + -1;
      uVar6 = uVar5;
    }
    uVar5 = uVar5 + 1;
    puVar4 = puVar4 + 4;
  } while ((int)uVar5 < 0x80);
  if (-1 < (int)uVar6) {
    uVar2 = func_0x800072e0();
    puVar7[1] = DAT_8012485c;
    DAT_8012485c = uVar6;
    func_0x80007300(uVar2);
  }
  return;
}
