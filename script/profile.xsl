<?xml version="1.0" encoding="WINDOWS-1251"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/TR/WD-xsl">
<xsl:template match="/">
<table border="1">
  <tr bgcolor="#CCCCCC">
    <td align="center"><strong>Summary</strong></td>
    <td align="center"><strong>Calls</strong></td>
    <td align="center"><strong>Average</strong></td>
	<td align="center"><strong>Address</strong></td>
	<td align="center"><strong>Function</strong></td>
  </tr>
  <xsl:for-each select="profiling/prof" order-by="number(@summary)" >
  <tr bgcolor="#F5F5F5">
    <td><xsl:value-of select="@summary"/></td>
    <td align="left"><xsl:value-of select="@calls"/> </td>
    <td><xsl:value-of select="@average"/></td>
	<td><xsl:value-of select="@addr"/></td>
	<td><xsl:value-of select="@name"/></td>
  </tr>
  </xsl:for-each>
</table>
</xsl:template>
</xsl:stylesheet>