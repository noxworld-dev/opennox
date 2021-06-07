package blobs

// FormatAccesses formats blob accesses in all source files.
func FormatAccesses() error {
	return RewriteAccess(func(a *Access) (bool, error) {
		return a.Expr.Val != a.String(), nil
	})
}
