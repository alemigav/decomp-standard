/* FUN_80066048
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80066048  body 0x80066048..0x800661e3  size 412 B
 * body sha256 2b82b97f32f9f752721191cb9a19e02e343abe82e34da9c59fb793816d5e3579
 * provider record sha256 db37a1538732633ef615489b82bb5b5d82d30275c1774cb2a26be9a3ad76c53f
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80066048(int param_1,short *param_2,int param_3,int param_4)

{
  bool bVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  int *piVar5;
  undefined4 uVar6;
  short *psVar7;
  int *piVar8;
  undefined4 *puVar9;
  ushort *puVar10;
  int *piVar11;
  short sVar12;
  int iVar13;
  short *in_t3;
  int local_28 [10];
  
  piVar11 = *(int **)(param_1 + 200);
  piVar5 = (int *)piVar11[3];
  piVar8 = local_28;
  if (piVar5 != (int *)0x0) {
    puVar9 = (undefined4 *)piVar11[1];
    iVar13 = 0;
    if (0 < *piVar11) {
      do {
        uVar6 = *puVar9;
        puVar9 = puVar9 + 4;
        iVar13 = iVar13 + 1;
        *piVar8 = uVar6;
        piVar8 = piVar8 + 1;
      } while (iVar13 < *piVar11);
    }
    if (iVar13 < 10) {
      piVar8 = local_28 + iVar13;
      do {
        *piVar8 = 0;
        iVar13 = iVar13 + 1;
        piVar8 = piVar8 + 1;
      } while (iVar13 < 10);
    }
    iVar13 = *piVar5;
    puVar10 = (ushort *)(piVar5 + iVar13 + 1);
    do {
      piVar5 = piVar5 + 1;
      sVar2 = *param_2;
      sVar3 = param_2[1];
      sVar4 = param_2[2];
      sVar12 = *(short *)piVar5;
      param_2 = param_2 + 3;
      if (sVar12 != 0) {
        in_t3 = (short *)(local_28[*puVar10] + (uint)puVar10[1] * 0x10);
        sVar12 = sVar12 + -1;
        puVar10 = puVar10 + 2;
        *in_t3 = (short)(*in_t3 * param_3 + sVar2 * param_4 >> 0xc);
        in_t3[1] = (short)(in_t3[1] * param_3 + sVar3 * param_4 >> 0xc);
        in_t3[2] = (short)(in_t3[2] * param_3 + sVar4 * param_4 >> 0xc);
      }
      while (bVar1 = sVar12 != 0, sVar12 = sVar12 + -1, bVar1) {
        psVar7 = (short *)(local_28[*puVar10] + (uint)puVar10[1] * 0x10);
        *psVar7 = *in_t3;
        puVar10 = puVar10 + 2;
        psVar7[1] = in_t3[1];
        psVar7[2] = in_t3[2];
      }
      iVar13 = iVar13 + -1;
    } while (iVar13 != 0);
  }
  return;
}
