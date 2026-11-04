/* FUN_80098088
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80098088  body 0x80098088..0x800981d7  size 336 B
 * body sha256 a0d83390562aa3a2ab8622a2cdb451b1eb414a0dc47754a788a58878affb85ae
 * provider record sha256 9e2254e203c28db49c79381049e4e187ad00e02036e3456e9390f8e01ba3660b
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80098088(void)

{
  undefined *puVar1;
  undefined2 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = 2;
  iVar5 = DAT_800c52dc + 0x3b828;
  puVar2 = (undefined2 *)(DAT_800c52dc + 0x3b80a);
  iVar4 = DAT_800c52dc + 0x3b800;
  puVar1 = &UNK_80131458;
  do {
    iVar3 = iVar3 + -1;
    FUN_80047b04(iVar4,0);
    FUN_8004786c(iVar4,0x80,0x80,0x80);
    FUN_800478ac(iVar4,puVar1[-4],puVar1[-3]);
    FUN_800479bc(iVar4,puVar1[-2],puVar1[-1]);
    *(undefined **)(puVar2 + 1) = &DAT_8012f530;
    *puVar2 = 0;
    puVar2 = puVar2 + 10;
    iVar4 = iVar4 + 0x14;
    puVar1 = puVar1 + -4;
  } while (iVar3 != 0);
  iVar4 = 0x20;
  do {
    FUN_80047b58(iVar5,1);
    FUN_8004788c(iVar5,0x80,0x80,0x80);
    *(undefined1 *)(iVar5 + 3) = 4;
    iVar4 = iVar4 + -1;
    iVar5 = iVar5 + 0x10;
  } while (iVar4 != 0);
  DAT_8012bffc = 10;
  DAT_8012bffe = 0x46;
  DAT_8012bfd4 = 0x3a;
  DAT_8012bff8 = 0;
  DAT_8012bffb = 0;
  DAT_8012bffa = 0;
  DAT_8012bfd6 = 0x1d;
  return;
}
